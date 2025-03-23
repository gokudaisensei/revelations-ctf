# Use your provided secure Alpine-based base image (ctf-base-alpine)
FROM ctf-base

# Switch to root to install build tools (build-base) and GDB
USER root

# Install build tools and GDB (Alpine's equivalent to build-essential)
RUN apk update && apk add --no-cache build-base gdb

# Copy the C source file into the /home/ctfuser directory
COPY mouse_trap_code.c /home/ctfuser/mouse_trap_code.c

# Compile the source file to create the binary "mouse_trap_code",
# then remove the source file for cleanliness
RUN gcc -o /home/ctfuser/mouse_trap_code /home/ctfuser/mouse_trap_code.c && \
    chown ctfuser:ctfuser /home/ctfuser/mouse_trap_code && chmod 755 /home/ctfuser/mouse_trap_code && \
    rm -f /home/ctfuser/mouse_trap_code.c

# Copy the MOTD file into a non-standard location
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our custom MOTD
RUN cp /opt/ctf/motd.txt /etc/motd

# Expose SSH port (assuming ctf-base-alpine already installs openssh-server)
EXPOSE 22

# Set working directory to the non-root user's home directory
WORKDIR /home/ctfuser

# Start the SSH service in the foreground so users can SSH in and solve the challenge.
CMD ["/usr/sbin/sshd", "-D"]
