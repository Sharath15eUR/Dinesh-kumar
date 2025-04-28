# MAC Layer Functionalities Across Planes

In IEEE 802.11, the MAC layer supports **three functional planes**: **Management**, **Control**, and **Data**. Each plane plays a specific role in wireless communication.

---

## **1. Management Plane**

Handles network organization and maintenance.

| Functionality           | Description |
|-------------------------|-------------|
| **Beacon Transmission** | Periodic broadcast by AP for synchronization and network availability. |
| **Authentication**      | Verifies identity of a station before associating. |
| **Association/Disassociation** | Establishes or terminates connection between STA and AP. |
| **Reassociation**       | Supports STA mobility between APs within the same ESS. |
| **Probe Request/Response** | Used by clients to discover APs in the vicinity. |
| **Deauthentication**    | Terminates authentication relationship explicitly. |
| **Capability Exchange** | Shares STA/AP supported features during association. |

---

## **2. Control Plane**

Supports reliable and collision-free transmission.

| Functionality           | Description |
|-------------------------|-------------|
| **RTS/CTS (Request to Send / Clear to Send)** | Collision avoidance mechanism (esp. in hidden node scenarios). |
| **ACK (Acknowledgment)** | Confirms successful reception of a frame. |
| **PS-Poll**             | Power-saving polling mechanism for buffered frames. |
| **Block ACK Request/Response** | Acknowledges a group of data frames together to reduce overhead. |

---

## **3. Data Plane**

Handles user data transfer.

| Functionality           | Description |
|-------------------------|-------------|
| **Frame Fragmentation/Reassembly** | Splits and combines large frames to fit within transmission limits. |
| **MAC Addressing**      | Uses RA/TA/DA/SA for accurate frame routing. |
| **Data Encapsulation**  | Wraps payload with MAC header and trailer (includes FCS). |
| **Sequence Control**    | Maintains proper ordering and manages duplicates. |
| **QoS Support**         | Prioritizes traffic using access categories (e.g., voice over data). |
| **Encryption/Decryption** | Secures frame payload (e.g., WPA2/WPA3). |

---

## **Conclusion**

- **Management Plane** → Network formation, connection handling.
- **Control Plane** → Medium access, delivery confirmation.
- **Data Plane** → Payload transmission, integrity, and security.

---
