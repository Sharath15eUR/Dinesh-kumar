# Medium Access Control (MAC) Methodologies

Medium Access Control methods define **how multiple devices share the same wireless medium** without collision, ensuring efficient and fair use of bandwidth.

---

## **Primary MAC Methodologies in IEEE 802.11**

### 1. **Distributed Coordination Function (DCF)**

| Feature        | Description |
|----------------|-------------|
| **Type**       | Contention-based |
| **Mechanism**  | Uses CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance) |
| **Backoff**    | Random backoff timer after sensing the medium is idle |
| **Optional RTS/CTS** | Avoids hidden node problem |
| **ACKs**       | Ensures reliable delivery via acknowledgment |

**Default method** in most Wi-Fi implementations.

---

### 2. **Point Coordination Function (PCF)**

| Feature        | Description |
|----------------|-------------|
| **Type**       | Contention-free |
| **Coordinator**| AP acts as a central scheduler during Contention-Free Period (CFP) |
| **Polling**    | AP polls STAs one-by-one for transmission |
| **Limited Use**| Rarely implemented in commercial systems |

Useful for **time-sensitive** traffic like voice, but largely replaced by newer QoS methods.

---

### 3. **Hybrid Coordination Function (HCF)** *(802.11e)*

| Feature         | Description |
|-----------------|-------------|
| **Combines**    | DCF + PCF |
| **QoS Support** | Introduces traffic categories (voice, video, best-effort, background) |
| **HCCA (HCF Controlled Channel Access)** | Central scheduling using transmission opportunity (TXOP) |
| **EDCA (Enhanced DCF)** | Prioritized contention access for QoS |

Designed for **multimedia and real-time applications**.

---

## **Conclusion**

| Method | Type            | Key Features                | Use Case              |
|--------|------------------|-----------------------------|------------------------|
| DCF    | Contention-based | CSMA/CA, ACK, RTS/CTS       | General data traffic   |
| PCF    | Contention-free  | AP polling, CFP             | Rare, legacy use       |
| HCF    | Hybrid            | QoS-aware, EDCA + HCCA      | Multimedia, real-time  |

---
