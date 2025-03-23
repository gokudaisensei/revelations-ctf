# CODE QUEST: TOM & JERRY

Welcome, contestants, to CODE QUEST: TOM & JERRY! In this event, you’ll face a series of challenges that mix general problem-solving, cryptography, web exploitation, reverse engineering, and binary exploitation – all with a twist of classic cartoon mischief. Whether it’s Tom’s desperate attempts to catch Jerry or Jerry’s devious counter-moves, every challenge is designed to test your skills and ingenuity. Remember, teamwork and creativity are key to outsmarting your rivals. Let the Great Quest begin!

---

## **Easy Challenges: Mouse Mayhem!**

### **1. Blueprint Blunder (General Skills)**

- **Category:** General Skills  
- **Difficulty:** Easy

**Description:**  
Tom’s in trouble – he accidentally swallowed Jerry *again*! Now the vet needs a clear X-ray to figure out what’s really inside that cat’s stomach. But, oh no – Jerry swapped the real X-ray film with a blurry doodle before the vet could use it! Your mission: use your tech wizardry to sharpen that image and reveal the hidden details. Only when the image is properly adjusted will the flag emerge, exposing the real problem brewing in Tom’s belly.

**Challenge File:**  

- `xray.png` (A blurry image of Tom's insides, potentially featuring a mischievous mouse)

**Solution Hint:**  

- Use an image manipulation tool (like ImageMagick) to adjust brightness and contrast.  
- For example, try:  

  ```bash
  magick xray.png -brightness-contrast 30x30 revealed.png
  ```  

  Tweak the parameters until the hidden flag is visible.

---

### **2. Triple-Wrapped Cheese-nigma (General Skills)**

- **Category:** General Skills  
- **Difficulty:** Easy

**Description:**  
Jerry’s locked away the “Special Reserve Cheddar” under layers of Base64 encryption – think of it as a cheesy Russian nesting doll! Tom desperately needs that cheese to set his latest trap. Your task is to peel away the layers of Base64 encoding and release the cheese-scented secret. Every decoding step brings you closer to unleashing the ultimate cheese flavor ranking.

**Challenge File:**  

- `cheese_lock.txt` (A file encoded repeatedly with Base64)

**Solution Hint:**  

- Use the Linux command:  

  ```bash
  base64 -d cheese_lock.txt > decoded.txt
  ```  

  Repeat the decoding process until the plain text (and flag) is revealed.

---

### **3. Rotisserie Recipe Robbery (Cryptography)**

- **Category:** Cryptography  
- **Difficulty:** Easy

**Description:**  
Jerry has pulled off another mischief! He’s taken Tom’s cherished recipe for Rotisserie Roasted Rat and scrambled it using a classic ROT13 cipher. Now, Tom’s left with a culinary calamity. Your mission is to reverse the ROT13 encryption and recover the secret recipe – or at least, reveal the true flag hidden in the text.

**Challenge File:**  

- `secret_recipe.txt` (A ROT13-obfuscated text file)

**Solution Hint:**  

- Use the command:  

  ```bash
  tr 'A-Za-z' 'N-ZA-Mn-za-m' < secret_recipe.txt > decoded.txt
  ```  

  This simple command will flip the letters back to reveal the flag.

---

### **4. Bulldog Biscuit Bonanza (Cryptography)**

- **Category:** Cryptography  
- **Difficulty:** Medium

**Description:**  
Spike, the slobbering bulldog, is guarding a mountain of dog biscuits – the Biscuit Fortress™! But Jerry’s cunning: he encrypted the biscuit vault’s access code with a Vigenère cipher. Luckily, Tom left subtle clues (crumbs) that hint at the key. Your challenge is to analyze the ciphertext, deduce the Vigenère keyword, and decrypt the file to reveal the secret cookie combo.

**Challenge File:**  

- `cookie_vault.txt` (A file encrypted with a Vigenère cipher)

**Solution Hint:**  

- Look for repeating patterns and hints within the ciphertext.  
- Use online Vigenère tools or local decryption libraries (or even our provided tool) to brute-force or guess the key.

---

### **5. The robots.txt Rescue (Web Exploitation)**

- **Category:** Web Exploitation  
- **Difficulty:** Easy

**Description:**  
Tom’s “Totally Secure Mouse Trap Emporium” website isn’t as secure as he thought – in fact, he left a glaring clue in the robots.txt file! By analyzing the file, you might uncover a hidden directory that points to the admin page, where the flag is secreted away. It’s like following a trail of breadcrumbs… or cheese!

**Challenge Setup:**  

- A target website (e.g., `http://example.com/tomsemporium/robots.txt`) contains clues in its disallowed directories.

**Solution Hint:**  

- Simply open the robots.txt file and look for any disallowed paths that hint at administrative access.  
- Follow those clues to find the flag.

---

### **6. Cookie Corruption (Web Exploitation)**

- **Category:** Web Exploitation  
- **Difficulty:** Medium

**Description:**  
Tom believes his cookie system secures his website – but Jerry knows better! A vulnerability in how cookies are handled allows you to manipulate authentication tokens and access the admin page. By altering the cookies in your browser, you can elevate your privileges and expose the hidden flag.

**Challenge Setup:**  

- The challenge is integrated into a web interface where modifying cookie values yields access to restricted content.

**Solution Hint:**  

- Use your browser’s developer tools to inspect and edit cookies.  
- Experiment until you unlock the admin-only view that reveals the flag.

---

## **Medium Challenges: Cat Comeuppance!**

### **7. Strings of Sausage (Reverse Engineering)**

- **Category:** Reverse Engineering  
- **Difficulty:** Easy

**Description:**  
Tom has hidden a glorious sausage in a binary file – a cheeky nod to his culinary misadventures. Although the binary is partially obfuscated, it contains constant strings that hint at the flag. Your mission is to extract these strings without needing to dive deep into disassembly.

**Challenge File:**  

- `hide_a_sausage` (A binary that conceals its secret with obfuscated string sequences)

**Solution Hint:**  

- Use the `strings` command to list all text within the binary:

  ```bash
  strings hide_a_sausage | grep SAUSAGE
  ```  

- Look for output matching the flag format.

---

### **8. Cracking Tom's Trap Code (Reverse Engineering)**

- **Category:** Reverse Engineering  
- **Difficulty:** Medium

**Description:**  
Tom has set a password in the middle of his mouse trap to catch Jerry. However, his code isn’t well-documented, and the password is hidden in the binary. Your task is to analyze the program’s execution flow and determine the correct password to disable the trap once and for all.

**Challenge File:**  

- `mouse_trap_code` (Tom's binary "trap" which requires the correct password to unlock)

**Solution Hint:**  

- Use a debugger (like GDB) to step through the binary and locate the password verification routine.  
- Trace the execution flow to find where the password is compared, then extract or bypass it to reveal the flag.

---

### **9. The Format String Funhouse (Binary Exploitation)**

- **Category:** Binary Exploitation  
- **Difficulty:** Medium

**Description:**  
Jerry has exploited a format string vulnerability in Tom’s cheese catalog printer. This vulnerability allows you to inject malicious format specifiers into the program, causing it to leak sensitive data or alter its behavior. Your challenge is to craft an input that exploits this vulnerability to reveal the flag hidden within the program’s output.

**Challenge File:**  

- A compiled executable (Tom's vulnerable cheese printing program)

**Solution Hint:**  

- Test the vulnerability by providing format specifiers (like `%x` or `%s`) as input.  
- Use a debugger (GDB) to inspect memory and adjust your payload until the flag is revealed.

---

### **10. The Shell Escape (Binary Exploitation)**

- **Category:** Binary Exploitation  
- **Difficulty:** Medium

**Description:**  
Jerry has found a way to escape from his mousetrap by exploiting a buffer overflow vulnerability in a binary program. The program prompts for input with a limited buffer, but this limitation is your ticket to executing arbitrary commands. Use your overflow skills to execute a shell command that reveals the flag stored in a protected directory.

**Challenge File:**  

- `passcodeshell.access` (A vulnerable binary that accepts user input, allowing buffer overflow exploitation)

**Solution Hint:**  

- Analyze the binary using a debugger to locate the overflow vulnerability.  
- Craft a payload that overflows the buffer and executes a shell command to read the flag.  
- Tools like GDB and pwntools can be very helpful for this challenge.

---

## **Final Notes**

**Flag Format:**  
All flags should be in the format `FLAG{...}` to ensure consistency.

**Challenge Progression:**  

- **Easy Challenges (1–6):**  
  These challenges introduce you to general skills such as image manipulation, simple encoding/decoding, basic web exploitation, and simple cryptography.
- **Medium Challenges (7–10):**  
  These require deeper reverse engineering and exploitation skills, challenging you to analyze binaries, debug code, and craft complex exploits.

**Hints & Tools:**  
Utilize command-line tools like `magick`, `base64`, `tr`, `strings`, `rev`, and debugging tools such as GDB. Each challenge comes with a hint to guide you without giving away the solution.

---

Good luck, and may your coding and investigative skills lead you to victory in CODE QUEST: TOM & JERRY!  
Remember: Every challenge is a step closer to outsmarting Tom and outmaneuvering Jerry in this epic quest.
