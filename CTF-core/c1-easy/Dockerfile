# Use your provided secure Alpine-based base image (ctf-base-alpine)
FROM ctf-base

# Switch to root to install additional packages and copy challenge files
USER root

# Install bash and su-exec (Alpine's lightweight alternative to gosu)
RUN apk add --no-cache bash su-exec

# Copy the challenge generation script into the home directory
COPY generate_magic.sh /home/ctfuser/generate_magic.sh
RUN chown ctfuser:ctfuser /home/ctfuser/generate_magic.sh && chmod +x /home/ctfuser/generate_magic.sh

# Copy the MOTD file to a non-standard location (we'll use it to update /etc/motd)
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our MOTD contents
RUN cp /opt/ctf/motd.txt /etc/motd

# Set working directory to the non-root user's home directory
WORKDIR /home/ctfuser

# Use su-exec to run the generation script as ctfuser, then switch back to root to launch sshd
ENTRYPOINT ["/bin/bash", "-c", "su-exec ctfuser /home/ctfuser/generate_magic.sh; exec /usr/sbin/sshd -D"]
