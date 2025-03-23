# Use a minimal Alpine base image for security
FROM alpine:latest

# Set environment variable to avoid caching (optional)
ENV ALPINE_NO_CACHE=true

# Create a non-root user for running challenges and set password
RUN adduser -D -s /bin/sh ctfuser && \
    echo "ctfuser:password123" | chpasswd && \
    mkdir -p /challenge && \
    chown -R ctfuser:ctfuser /challenge

# Install only necessary utilities: coreutils, netcat-openbsd, binutils, and openssh
RUN apk update && \
    apk add --no-cache coreutils netcat-openbsd binutils openssh && \
    rm -rf /var/cache/apk/*

# Configure SSH:
# Create the SSH runtime directory and update the sshd_config for secure password authentication
RUN mkdir -p /var/run/sshd && \
    echo "PermitRootLogin no" >> /etc/ssh/sshd_config && \
    echo "PasswordAuthentication yes" >> /etc/ssh/sshd_config && \
    echo "AllowUsers ctfuser" >> /etc/ssh/sshd_config

# Generate SSH host keys so that sshd can start without errors
RUN ssh-keygen -A

# Expose SSH port
EXPOSE 22

# Start SSH service in the foreground
CMD ["/usr/sbin/sshd", "-D"]
