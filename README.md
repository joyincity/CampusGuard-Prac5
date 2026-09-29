# CampusGuard-Prac5
CampusGuard, an emergency-response coordination platform for a large university campus.

# CampusGuard

## Running normally

Build the application:

```bash
make
```

Run the application:

```bash
make run
```

Clean the compiled files:

```bash
make clean
```

## Running with Docker

Build and run the application using Docker Compose:

```bash
docker compose up --build
```

To stop the application:

```bash
docker compose down
```

## Docker Build

To build the Docker image manually:

```bash
docker build -t campusguard .
```

To run the Docker image:

```bash
docker run --rm campusguard
```
