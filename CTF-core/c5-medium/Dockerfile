# Use your provided secure Debian-based base image (ctf-base-debian)
FROM ctf-base-debian

# Switch to root to install build tools and compile the C code
USER root

# Install build-essential (Debian equivalent to build-base) and other utilities
RUN apt-get update && \
    apt-get install -y build-essential xxd gdb file python3 python3-pip && \
    pip3 install --break-system-packages pwntools && \
    rm -rf /var/lib/apt/lists/*

# Copy the C source file into the /home/ctfuser directory
COPY passcodeshell.c /home/ctfuser/passcodeshell.c

# Compile the source file to create the binary "passcodeshell" using GNU89 standard,
# then remove the source file for cleanliness.
RUN gcc -std=gnu89 -o /home/ctfuser/passcodeshell /home/ctfuser/passcodeshell.c -fno-stack-protector -no-pie && \
    rm -f /home/ctfuser/passcodeshell.c

# Set the binary to be owned by root and set the setuid bit
RUN chown root:root /home/ctfuser/passcodeshell && chmod 4755 /home/ctfuser/passcodeshell

# Copy the MOTD file into the /opt/ctf directory (non-standard location)
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our custom MOTD
RUN cp /opt/ctf/motd.txt /etc/motd

# Copy the flag file from the build context into /home/ctfuser
COPY flag.txt /home/ctfuser/flag.txt
RUN chown ctfuser:ctfuser /home/ctfuser/flag.txt && chmod 644 /home/ctfuser/flag.txt

# Create the protected directory and move the flag file there with restricted permissions.
RUN mkdir -p /protected && \
    mv /home/ctfuser/flag.txt /protected/flag.txt && \
    chown root:root /protected/flag.txt && chmod 600 /protected/flag.txt && \
    chown root:root /protected && chmod 700 /protected

# Expose SSH port (assuming ctf-base-debian already installs openssh-server)
EXPOSE 22

# Set working directory to the non-root user's home directory
WORKDIR /home/ctfuser

# Start the SSH service in the foreground so that users can SSH in and solve the challenge.
CMD ["/usr/sbin/sshd", "-D"]
