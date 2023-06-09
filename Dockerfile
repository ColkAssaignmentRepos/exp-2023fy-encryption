# Use an official Ubuntu runtime as a parent image
FROM ubuntu:18.04 AS base

# Set the working directory
WORKDIR /work/aes

# Install necessary tools
RUN apt-get update && apt-get install -y --no-install-recommends \
    gcc=4:7.4.0-1ubuntu2.3 \
    make=4.1-9.1ubuntu1 \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# For the final stage, start again with a clean Ubuntu image
FROM ubuntu:18.04

# Set the working directory
WORKDIR /work/aes

# Copy only the necessary from the previous stage
COPY --from=base /usr/bin/gcc /usr/bin/gcc
COPY --from=base /usr/bin/make /usr/bin/make
COPY --from=base /usr/bin/cmake /usr/bin/cmake

# Set the entrypoint
ENTRYPOINT ["top", "-b"]
