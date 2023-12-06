FROM ubuntu:latest as build

RUN apt update && apt upgrade -y && apt install -y \
  build-essential \
  g++ \
  libboost-all-dev \
  cmake \
  vim

RUN useradd -ms /bin/bash --uid 1001 --home /build --create-home build-user \
  && chown build-user:build-user /build \
  && chmod -R 775 /build

USER build-user

WORKDIR /build

COPY --chown=build-user:build-user . .

RUN cmake -S . -B Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=Release/install \
  && cmake --build Release -j4 \
  && cmake --build Release -t install

FROM ubuntu:latest

RUN apt update && apt upgrade -y

RUN useradd -ms /bin/bash --uid 1001 app-user \
  && mkdir /app \
  && chown app-user:app-user /app \
  && chmod -R 775 /app

USER app-user

WORKDIR /app

COPY --from=build --chown=app-user:app-user /build/Release/install/bin /app/bin
COPY --from=build --chown=app-user:app-user /build/Release/install/lib /app/lib

ENV LD_LIBRARY_PATH=/app/lib:${LD_LIBRARY_PATH}

CMD [ "./bin/dummy-cpp", "-i", "data/input-test.csv", "-o", "data/output.csv" ]
