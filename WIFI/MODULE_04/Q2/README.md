# 802.11 MAC Frame Format

The **802.11 MAC header** is a key part of Wi-Fi communication, used to manage and deliver frames across wireless networks. The MAC header precedes the frame body and varies in size based on control info.

---

## **Fields & Their Purpose**

| Field              | Description                                                                 |
|--------------------|-----------------------------------------------------------------------------|
| **Frame Control**  | 16-bit field with frame type, subtype, control flags (To DS, From DS, etc.). |
| **Duration/ID**    | Indicates duration for which the channel is reserved; used in NAV.           |
| **Address 1**      | Receiver Address (RA): Device that receives the frame.                       |
| **Address 2**      | Transmitter Address (TA): Device that originally sent the frame.             |
| **Address 3**      | Destination Address (DA): Final destination in the network.                  |
| **Sequence Control** | Combines fragment number and sequence number for frame ordering.           |
| **Address 4** *(Optional)* | Used in WDS (Wireless Distribution System) for intermediate hops.     |
| **QoS Control** *(Optional)* | Present in QoS frames for traffic priority handling.              |
| **HT Control** *(Optional)* | Used in high-throughput (802.11n) for advanced PHY control.         |
| **Frame Body**     | Actual data payload being transmitted.                                       |
| **FCS (Frame Check Sequence)** | 32-bit CRC for error detection.                                |

---

## **Conclusion**

- **802.11 MAC Header** enables control, addressing, and error detection.
- **Variable structure** based on type (Data, Control, Management).
- Designed to support **mobility, security, and quality of service** in wireless environments.

---
