# Use your provided secure base image for Alpine (assuming it's named ctf-base-alpine)
FROM ctf-base

# Switch to root to install build tools and compile the C code
USER root

# Install build tools (build-base is Alpine's equivalent of build-essential)
RUN apk update && apk add --no-cache build-base

# Copy the C source file into the /home/ctfuser directory
COPY hide_a_sausage.c /home/ctfuser/hide_a_sausage.c

# Compile the source file to create the binary "hide_a_sausage",
# then remove the source file for cleanliness
RUN gcc -o /home/ctfuser/hide_a_sausage /home/ctfuser/hide_a_sausage.c && \
    chown ctfuser:ctfuser /home/ctfuser/hide_a_sausage && chmod 755 /home/ctfuser/hide_a_sausage && \
    rm -f /home/ctfuser/hide_a_sausage.c

# Copy the MOTD file into the home directory (so it's automatically shown on SSH login)
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our MOTD contents
RUN cp /opt/ctf/motd.txt /etc/motd

# Expose SSH port (if not already exposed by ctf-base-alpine)
EXPOSE 22

# Set working directory to the user's home directory
WORKDIR /home/ctfuser

# Start the SSH service in the foreground so that users can SSH in and solve the challenge.
CMD ["/usr/sbin/sshd", "-D"]
