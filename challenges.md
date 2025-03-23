# CODE QUEST – Challenge Set Writeup

Welcome to CODE QUEST! Below is the challenge set for the event. Each challenge tests a different skill—from basic file manipulation and decoding to advanced reverse engineering and binary exploitation. Read each challenge’s details carefully and follow the hints provided. Good luck, and let your quest begin!

---

## **Easy Challenges**

### **1. Hidden Message (General Skills)**

**Category:** General Skills  
**Difficulty:** Easy

**Description:**  
You have discovered a picture with a smudged message written in the corner. When zoomed in and the image’s brightness/contrast are tweaked, it appears that the file contains a flag hidden within its subtle details. Your challenge is to use image editing techniques to adjust the light and color parameters until the hidden text is revealed.

**Challenge File:**  

- `image.png` (Contains the hidden flag when proper adjustments are applied.)

**Solution Hint:**  

- Use image manipulation tools (e.g., ImageMagick) to boost contrast and brightness until the flag becomes visible.  
- Experiment with commands like:  

  ```bash
  magick image.png -brightness-contrast 30x30 revealed.png
  ```

---

### **2. Base64 Fun (General Skills)**

**Category:** General Skills  
**Difficulty:** Easy

**Description:**  
A friend tried encrypting this file using repeated Base64 encoding. The resulting text is an assortment of encoded strings that must be decoded step by step. Your challenge is to reverse the multiple layers of Base64 encoding until you obtain the plain text message.

**Challenge File:**  

- `text.txt` (Encoded repeatedly with Base64)

**Solution Hint:**  

- Use common Linux encoding tools (e.g., `base64 -d`) in a loop until the message becomes plain text.  
- For example:

  ```bash
  base64 -d text.txt > decoded.txt
  # Repeat until decoded.txt becomes legible.
  ```

---

### **3. ROT13 Simple (Cryptography)**

**Category:** Cryptography  
**Difficulty:** Easy

**Description:**  
You received a file that appears to be ROT13 encrypted. The file hints that the message is rotated. Your task is to determine the correct rotation—likely ROT13—and decode the file to reveal the flag.

**Challenge File:**  

- `message.txt` (ROT13-encrypted text)

**Solution Hint:**  

- Use the Linux `tr` command to reverse ROT13:

  ```bash
  tr 'A-Za-z' 'N-ZA-Mn-za-m' < message.txt > decoded.txt
  ```

- Check the output until the plain text flag is visible.

---

### **4. Vigenere (Cryptography)**

**Category:** Cryptography  
**Difficulty:** Medium

**Description:**  
An old colleague used a Vigenère cipher to secure sensitive communication. The encrypted file contains a password used for a communication tool. Your challenge is to deduce the keyword and decrypt the file to obtain the secret value.

**Challenge File:**  

- `encrypted_file.txt` (Encrypted with Vigenère cipher)

**Solution Hint:**  

- Analyze the ciphertext for repeating patterns.  
- Use online Vigenère decryption tools or local libraries (e.g., using Python’s `pycipher`) to try different keywords.  
- Look for clues in the file that hint at the key used by the agent.

---

### **5. robots.txt (Web Exploitation)**

**Category:** Web Exploitation  
**Difficulty:** Easy

**Description:**  
A website’s administrative backend is protected, but its configuration can be indirectly discovered through its `robots.txt` file. By analyzing `robots.txt`, you can determine the location of hidden administrative pages that store the flag.

**Challenge Setup:**  

- The target website has a `robots.txt` file (e.g., `http://example.com/robots.txt`) that indexes directories containing admin content.

**Solution Hint:**  

- Access the `robots.txt` file in your browser.  
- Look for disallowed paths or hints about administrative directories.  
- Visit the hinted URL to locate the flag.

---

### **6. Cookie Monster (Web Exploitation)**

**Category:** Web Exploitation  
**Difficulty:** Medium

**Description:**  
Cookies play a critical role in authentication. In this challenge, a web application stores user roles and authentication tokens in cookies. However, there’s a vulnerability in how the cookies are handled. Your task is to modify cookie values to elevate privileges and access an admin-only page where the flag is revealed.

**Challenge Setup:**  

- A web application (or simulated environment) where cookie manipulation leads to a hidden admin page.

**Solution Hint:**  

- Inspect cookies using browser developer tools.  
- Experiment with altering cookie values until the admin page is accessible, revealing the flag.

---

## **Medium Challenges**

### **7. strings it (Reverse Engineering)**

**Category:** Reverse Engineering  
**Difficulty:** Easy

**Description:**  
A binary file appears to hide its secrets among its strings. Although the program is partially obfuscated, it still contains constant string sequences that could include a flag. Your task is to extract these strings without deep disassembly.

**Challenge File:**  

- `binaryfile` (A binary containing obfuscated strings)

**Solution Hint:**  

- Use tools like the `strings` command:

  ```bash
  strings binaryfile | grep FLAG
  ```

- Look for text that matches the flag format.

---

### **8. Simple Crack (Reverse Engineering)**

**Category:** Reverse Engineering  
**Difficulty:** Medium

**Description:**  
A password-protected binary is provided with little documentation. The source code seems scrambled, but using debugging and reverse engineering techniques, you can trace the execution flow to reveal the correct password and unlock the program.

**Challenge File:**  

- `reverseme` (A binary file that behaves differently based on input)

**Solution Hint:**  

- Use a debugger (e.g., GDB) to analyze the program flow.  
- Identify where the password check occurs and trace the conditions that lead to the flag being printed.
- Try different inputs or patch the binary in memory to bypass the check.

---

### **9. Format String (Binary Exploitation)**

**Category:** Binary Exploitation  
**Difficulty:** Medium

**Description:**  
A compiled binary contains a format string vulnerability in how it prints user-provided input. This flaw can be exploited to inject a malicious format string, enabling you to read or write memory and eventually extract the flag.

**Challenge File:**  

- A compiled vulnerable program (provided as an executable)

**Solution Hint:**  

- Identify the vulnerability by running the program and providing format specifiers (e.g., `%x`, `%s`).  
- Craft an input that leaks memory or overwrites a pointer to display the flag.
- Use tools like `printf` debugging or GDB to help craft your exploit.

---

### **10. Shell Me (Binary Exploitation)**

**Category:** Binary Exploitation  
**Difficulty:** Medium

**Description:**  
A binary file prompts you for input using a function with limited bounds (like `fgets`). Due to improper input length checking, a buffer overflow vulnerability exists. Your challenge is to exploit this overflow to execute shell commands. The flag is stored at a restricted location on the system.

**Challenge File:**  

- A vulnerable binary (e.g., `passcodeshell.access`)

**Solution Hint:**  

- Analyze the binary with a debugger to locate the buffer overflow vulnerability.  
- Craft an input payload that overflows the buffer and executes a shell command to read the flag.
- Use tools like `gdb`, `pwntools`, or even custom Python scripts to generate your exploit payload.

---

## **Final Notes**

- **Flag Format:**  
  Each challenge’s flag should follow a consistent format (e.g., `FLAG{...}`) for easy validation.
  
- **Challenge Order:**  
  The Easy challenges (1–6) are intended to familiarize you with basic file manipulation, decoding, and web exploitation tasks.  
  The Medium challenges (7–10) demand deeper reverse engineering or exploitation skills and are designed to be more challenging.

- **Hints & Tools:**  
  Each challenge comes with a set of hints. Use the provided command-line tools (such as `tr`, `base64`, `strings`, `rev`, `gdb`, etc.) to complete the challenges.

Test all challenges thoroughly to ensure that each intended solution path works as expected and that the hints provide enough guidance for participants without giving away the answer.

Good luck to all participants, and let the CODE QUEST begin!

---

Feel free to modify any details or add additional hints as needed to better match your event’s theme and difficulty. Let me know if you need further adjustments or additional challenge details!
