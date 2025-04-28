# EAPOL 4-Way Handshake (802.1X/WPA2)

The **4-way handshake** is used in WPA2/WPA3 to establish a secure link between a client (STA) and access point (AP), enabling encrypted communication.

---

## **Precondition**

Both STA and AP must **share the Pairwise Master Key (PMK)**, derived via:
- 802.1X authentication (Enterprise)
- PSK (Pre-Shared Key) in WPA2-Personal

---

## **4-Way Handshake Steps**

### **Message 1: ANonce → STA**
- AP sends a **random nonce (ANonce)** to the STA.
- Purpose: Initiate key generation using both ANonce and SNonce.

### **Message 2: SNonce + MIC → AP**
- STA sends:
  - Its **random nonce (SNonce)**
  - **Message Integrity Code (MIC)** using PMK
- Purpose: Allows both sides to compute the **Pairwise Transient Key (PTK)**.

### **Message 3: GTK + MIC → STA**
- AP sends:
  - **Group Temporal Key (GTK)** encrypted with PTK
  - MIC for integrity
- Purpose: STA installs PTK + GTK for unicast & multicast traffic.

### **Message 4: ACK → AP**
- STA sends an acknowledgment.
- Purpose: Confirms successful key installation and completes the handshake.

---

## **Keys Derived**

| Key        | Purpose |
|------------|---------|
| **PMK**    | Base key derived from PSK or 802.1X; never transmitted. |
| **PTK**    | Session key for securing unicast traffic; derived from PMK + ANonce + SNonce + MACs. |
| **GTK**    | Shared key for multicast/broadcast; distributed by AP. |
| **MIC**    | Integrity check for handshake messages using PTK.

---

## **Conclusion**

- **4 messages** → Exchange nonces, derive keys, and install them.
- Ensures mutual authentication, confidentiality, and integrity.
- Basis for **secure WPA2/WPA3 communication**.

---

