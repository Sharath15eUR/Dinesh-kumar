# How the 4-Way Handshake Ensures Mutual Authentication

The 4-Way Handshake in Wi-Fi security not only establishes encryption keys but also ensures **mutual authentication** between the client (STA) and the access point (AP).

---

## **Mutual Authentication in the 4-Way Handshake**

1. **STA Proves Knowledge of the PMK**  
   - The client (STA) proves it has the correct Pairwise Master Key (PMK) by deriving the same Pairwise Transient Key (PTK) as the AP.
   - This prevents unauthorized devices from gaining access to the network.

2. **AP Proves Knowledge of the PMK**  
   - The access point also proves it has the PMK by sending a message encrypted with the PTK, which only the correct STA can decrypt.
   
3. **Verification via Nonces**  
   - Both sides (STA and AP) use nonces (random numbers) in their communication.  
   - If the messages and the nonces match, both sides authenticate each other.

4. **Confirmation of Encryption Setup**  
   - Both STA and AP send confirmation messages to verify that they have generated the same PTK.
   - The encryption keys used for data frames are securely established and confirmed.

---

## **Key Points**

- **Mutual Authentication** happens through the **secure exchange of cryptographic information** (PMK, PTK, and nonces).
- **Both parties prove** they know the correct PMK without ever directly transmitting it.
- The 4-Way Handshake ensures the STA and AP are communicating with the **same shared secret** (PMK) before proceeding with secure data transfer.

---

## **Conclusion**

- The 4-Way Handshake ensures **mutual authentication** by allowing both the STA and AP to independently verify each other's knowledge of the **Pairwise Master Key (PMK)**.
- This process is critical for preventing unauthorized access and ensuring secure communication in Wi-Fi networks.

---