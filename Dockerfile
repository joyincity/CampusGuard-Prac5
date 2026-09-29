FROM ubuntu:24.04

# Install the C++ compiler and Make
RUN apt-get update && \
    apt-get install -y g++ make && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the project files
COPY . .

# build
RUN make

# run the application
CMD ["./CampusGuard"]
