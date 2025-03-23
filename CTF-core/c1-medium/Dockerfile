# Use your provided secure Alpine-based base image (ctf-base-alpine)
FROM ctf-base

# Switch to root to install additional packages and copy challenge files
USER root

# Install ImageMagick for image manipulation
RUN apk update && \
    apk add --no-cache imagemagick && \
    rm -rf /var/cache/apk/*

# Copy the challenge image file into the home directory of ctfuser
COPY image.png /home/ctfuser/image.png
RUN chown ctfuser:ctfuser /home/ctfuser/image.png && chmod 644 /home/ctfuser/image.png

# Copy the MOTD file into a non-standard location (here, /opt/ctf/)
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our MOTD contents
RUN cp /opt/ctf/motd.txt /etc/motd

# Expose SSH port (assuming ctf-base-alpine already installs openssh)
EXPOSE 22

# Start the SSH service in the foreground so users can SSH in and use the provided tools.
CMD ["/usr/sbin/sshd", "-D"]
