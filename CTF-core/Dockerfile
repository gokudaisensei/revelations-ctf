# Use a minimal Debian base image for security
FROM debian:latest

# Security: Disable interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Create a non-root user for running challenges
RUN useradd -m -s /bin/bash ctfuser && \
    echo 'ctfuser:password123' | chpasswd && \
    mkdir -p /challenge && \
    chown -R ctfuser:ctfuser /challenge

# Install only necessary utilities
RUN apt-get update && apt-get install -y \
    coreutils \
    netcat-openbsd \
    binutils \
    openssh-server \
    && rm -rf /var/lib/apt/lists/*

# Security: Configure SSH for password authentication
RUN mkdir -p /var/run/sshd && \
    echo "PermitRootLogin no" >> /etc/ssh/sshd_config && \
    echo "PasswordAuthentication yes" >> /etc/ssh/sshd_config && \
    echo "AllowUsers ctfuser" >> /etc/ssh/sshd_config

# Generate SSH host keys so that sshd can start without errors
RUN /usr/bin/ssh-keygen -A

# Expose SSH port
EXPOSE 22

# Start SSH service in the foreground
CMD ["/usr/sbin/sshd", "-D"]

