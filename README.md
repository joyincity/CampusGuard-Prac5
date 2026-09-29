# CampusGuard-Prac5
CampusGuard, an emergency-response coordination platform for a large university campus.

## Running normally
Build the application:

```bash
make
```

Run:

```bash
make run
```

Clean the compiled files:

```bash
make clean
```

## Running with Docker
Build and run:

```bash
docker compose up --build
```

Stop:

```bash
docker compose down
```

## Docker Build

To build manually:

```bash
docker build -t campusguard .
```

Run:

```bash
docker run --rm campusguard
```
