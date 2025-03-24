# Use Alpine as the base image
FROM ctf-base

# Switch to root to install build tools and copy files
USER root

# Install Alpine's equivalent of build-essential (gcc and make)
RUN apk add --no-cache build-base

# Copy the Vigenère decryption C source file into the container
COPY vig_decrypt.c /home/ctfuser/vig_decrypt.c

# Compile the C program, place the executable in /home/ctfuser/, and remove the source file
RUN gcc -o /home/ctfuser/vig_decrypt /home/ctfuser/vig_decrypt.c && \
    chown ctfuser:ctfuser /home/ctfuser/vig_decrypt && chmod +x /home/ctfuser/vig_decrypt && \
    rm -f /home/ctfuser/vig_decrypt.c

# Copy the encrypted challenge file into the home directory
COPY cookie_vault.txt /home/ctfuser/cookie_vault.txt
RUN chown ctfuser:ctfuser /home/ctfuser/cookie_vault.txt && chmod 644 /home/ctfuser/cookie_vault.txt

# Copy the MOTD file into the /opt/ctf directory (non-standard location)
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Overwrite /etc/motd with our MOTD contents
RUN cp /opt/ctf/motd.txt /etc/motd

# Expose SSH port (if not already exposed by ctf-base)
EXPOSE 22

# Set working directory to the user's home directory
WORKDIR /home/ctfuser

# Start the SSH service in the foreground so users can SSH in and use the provided tools.
CMD ["/usr/sbin/sshd", "-D"]
