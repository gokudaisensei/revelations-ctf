# Use your provided secure Alpine-based base image (ctf-base-alpine)
FROM ctf-base

# Switch to root to install build tools and compile the C code
USER root

# Install build tools (build-base is Alpine's equivalent to build-essential)
RUN apk update && apk add --no-cache build-base gdb

# Copy the vulnerable C source file into the /home/ctfuser directory
COPY format_funhouse.c /home/ctfuser/format_funhouse.c

# Compile the source file to create the binary "format_funhouse",
# then remove the source file for cleanliness
RUN gcc -o /home/ctfuser/format_funhouse /home/ctfuser/format_funhouse.c && \
    chown ctfuser:ctfuser /home/ctfuser/format_funhouse && chmod 755 /home/ctfuser/format_funhouse && \
    rm -f /home/ctfuser/format_funhouse.c

# Copy the MOTD file into a non-standard location (/opt/ctf)
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
