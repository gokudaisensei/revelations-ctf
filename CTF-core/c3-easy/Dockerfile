# Use a lightweight Alpine-based Python image
FROM python:3.9-alpine

# Set working directory
WORKDIR /website

# Copy website files into the container
COPY robots.txt /website/robots.txt
COPY index.html /website/index.html
COPY admin/ /website/admin/

# Expose port 8000 for HTTP access
EXPOSE 8000

# Start a simple HTTP server to serve the website
CMD ["python", "-m", "http.server", "8000"]
