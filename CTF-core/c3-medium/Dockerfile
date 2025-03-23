# Use a lightweight Alpine-based Python image
FROM python:3.9-alpine

# Set the working directory
WORKDIR /app

# Install build dependencies for compiling Python packages (if needed)
RUN apk add --no-cache gcc musl-dev

# Install Flask
RUN pip install flask && apk del gcc musl-dev

# Copy the application code
COPY app.py /app/app.py

# Copy the templates directory
COPY templates/ /app/templates/

# Expose port 8000 for the Flask app
EXPOSE 8000

# Set the command to run the Flask application
CMD ["python", "app.py"]
