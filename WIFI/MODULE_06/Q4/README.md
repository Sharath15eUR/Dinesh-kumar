# Why WEP is Considered Insecure Compared to WPA2 or WPA3

WEP was the original Wi-Fi security protocol but is now considered highly insecure due to major design flaws and weak encryption methods.

---

## **Reasons for WEP Insecurity**

1. **Weak Encryption Algorithm**  
   - Uses RC4 with short 40/104-bit keys, easily breakable.
   - Initialization Vectors (IVs) are too small (24 bits) and repeat frequently.

2. **Poor Key Management**  
   - Keys are manually set and rarely changed, making networks vulnerable over time.

3. **Vulnerability to Attacks**  
   - Tools can crack WEP keys in minutes using passive eavesdropping and IV collection.
   - Attacks like FMS (Fluhrer, Mantin, Shamir) exploit WEP’s weak IV implementation.

4. **No Protection Against Replay Attacks**  
   - WEP cannot detect if an attacker reuses captured packets to gain unauthorized access.

---

## **Comparison to WPA2 and WPA3**

| Feature           | WEP                    | WPA2                    | WPA3                      |
|-------------------|-------------------------|--------------------------|----------------------------|
| Encryption        | RC4 (weak)              | AES (strong)             | AES (stronger with 192-bit) |
| Key Management    | Static Keys             | Dynamic Key Management   | Dynamic + SAE Authentication |
| Attack Resistance | Very low                | High (with WPA2-Enterprise) | Very high (even against brute-force) |

---

## **Key Points**

- WEP can be cracked within minutes, even by amateur attackers.
- WPA2 introduced strong AES encryption and dynamic keys.
- WPA3 further improved security with SAE and forward secrecy.

---
