# Client Association Process in 802.11

The **association process** is how a client (STA) formally joins an access point (AP) to begin data communication. It follows **scanning** and **authentication**.

---

## **Association Steps**

1. **Scanning**  
   STA discovers nearby APs (via passive or active scanning).

2. **Authentication**  
   STA and AP perform mutual authentication (open or shared key) to verify identity.

3. **Association Request**  
   STA sends an Association Request frame to the selected AP.  
   Includes:
   - Supported data rates  
   - SSID  
   - Capability info  
   - Security parameters

4. **Association Response**  
   AP responds with either:
   - **Success** → STA gets AID (Association ID)  
   - **Failure** → STA must retry or pick another AP

5. **Connected State**  
   After successful association, STA is part of the BSS (Basic Service Set) and can send/receive data.

---

## **Key Points**

- Required for any **data transmission** in infrastructure mode.
- Association is **one-to-one** between STA and AP.
- AP may reject association if max clients are reached or capability mismatch occurs.

---

## **Conclusion**

- **Authentication → Association → Data Transfer**
- Final step before full client participation in the WLAN.
- Enables **resource allocation, routing, and QoS control** at the MAC layer.

---
