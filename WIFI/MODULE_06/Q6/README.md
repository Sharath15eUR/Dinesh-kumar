# Role of the Pairwise Master Key (PMK) in the 4-Way Handshake

The Pairwise Master Key (PMK) is a critical element used during the 4-Way Handshake to establish secure, encrypted communication between a client (STA) and an access point (AP).

---

## **Purpose of PMK**

- **Foundation for Encryption**  
  - The PMK is the root key from which session-specific encryption keys are derived.
  
- **Used to Generate PTK**  
  - The 4-Way Handshake uses the PMK, along with nonces and MAC addresses, to generate the Pairwise Transient Key (PTK), which encrypts data frames.

- **Maintains Confidentiality**  
  - By deriving session keys from the PMK, even if one session is compromised, other sessions remain secure.

---

## **4-Way Handshake Process Involving PMK**

1. **Exchange Nonces**  
   - AP sends a random number (ANonce) to the STA.

2. **PTK Generation**  
   - Both STA and AP use PMK + ANonce + SNonce (STA’s random number) + MAC addresses to derive the PTK.

3. **Key Confirmation**  
   - Both sides confirm that they have derived the same PTK without directly transmitting it.

4. **Install Encryption Keys**  
   - The derived keys are used to encrypt unicast data frames between the STA and the AP.

---

## **Key Points**

- **PMK** is **never transmitted** over the air.
- **PTK** is dynamically generated for each session using the PMK.
- The 4-Way Handshake ensures **mutual proof** of possession of the PMK without revealing it.

---

## **Conclusion**

- The **PMK acts as the master secret** for securing Wi-Fi sessions.
- It enables the **secure, dynamic creation of encryption keys** essential for protecting wireless data transmission.

---