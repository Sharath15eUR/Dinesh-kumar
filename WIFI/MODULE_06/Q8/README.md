# What Happens if We Put a Wrong Passphrase During a 4-Way Handshake

If an incorrect passphrase is provided during the 4-Way Handshake, the authentication and key establishment process will fail, preventing the client (STA) from joining the Wi-Fi network.

---

## **Process with a Wrong Passphrase**

1. **PMK Generation Failure**  
   - The passphrase is used to generate the Pairwise Master Key (PMK).
   - With the wrong passphrase, both the client and the access point (AP) generate mismatched PMKs.

2. **Key Mismatch in PTK Derivation**  
   - The mismatched PMKs will result in different Pairwise Transient Keys (PTK) being derived.
   - Since both devices derive different keys, they cannot encrypt or decrypt messages correctly.

3. **Authentication Failure**  
   - During the 4-Way Handshake, the STA will fail to correctly decrypt or authenticate the messages from the AP.
   - The AP will not receive the expected confirmation from the STA, and the connection will be denied.

4. **No Successful Connection**  
   - The client (STA) will be unable to complete the handshake, and thus the AP will not allow network access.
   - The client will either receive an error or simply not be able to associate with the AP.

---

## **Key Points**

- The **correct passphrase** is required to generate a matching PMK for both the client and the AP.
- A **wrong passphrase** results in **mismatched keys**, leading to a failed 4-Way Handshake and **no network access**.

---

## **Conclusion**

- If a wrong passphrase is provided during the 4-Way Handshake, the network connection fails, as both the STA and AP cannot derive matching keys for encryption and authentication.
- It’s essential to provide the correct passphrase for successful authentication and secure communication.

---