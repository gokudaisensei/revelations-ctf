# Use your provided secure base image (ctf-base)
FROM ctf-base

# Switch to root to copy challenge files
USER root

# Copy the ROT13 challenge file into the /home/ctfuser directory
COPY theRotator.txt /home/ctfuser/theRotator.txt
RUN chown ctfuser:ctfuser /home/ctfuser/theRotator.txt && chmod 644 /home/ctfuser/theRotator.txt

# Copy the MOTD file (with challenge instructions) into the home directory
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our MOTD contents
RUN cp /opt/ctf/motd.txt /etc/motd

# Set working directory to the user's home directory
WORKDIR /home/ctfuser

# Expose SSH port so users can SSH into the container
EXPOSE 22

# Start SSH daemon in the foreground
CMD ["/usr/sbin/sshd", "-D"]

