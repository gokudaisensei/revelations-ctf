# Use your provided secure base image (ctf-base)
FROM ctf-base

# Switch to root to copy challenge files and set up host keys if needed
USER root

# Copy the challenge generation script into the home directory
COPY generate_magic.sh /home/ctfuser/generate_magic.sh
RUN chown ctfuser:ctfuser /home/ctfuser/generate_magic.sh && chmod +x /home/ctfuser/generate_magic.sh

# Copy the MOTD file to a non-standard location so that it isn't immediately visible
COPY motd.txt /opt/ctf/motd.txt
RUN chown ctfuser:ctfuser /opt/ctf/motd.txt && chmod 644 /opt/ctf/motd.txt

# Append a command to the user's .bashrc to display the hidden MOTD on login
RUN echo "\n# Display CODE QUEST MOTD on login from hidden location\nif [ -f /opt/ctf/motd.txt ]; then\n  cat /opt/ctf/motd.txt\nfi\n" >> /home/ctfuser/.bashrc

# Set working directory
WORKDIR /home/ctfuser

# Use runuser to execute the generation script as ctfuser, then start sshd as root.
ENTRYPOINT ["/bin/bash", "-c", "runuser -l ctfuser -c 'if [ -f /home/ctfuser/generate_magic.sh ]; then /home/ctfuser/generate_magic.sh; fi'; exec /usr/sbin/sshd -D"]

