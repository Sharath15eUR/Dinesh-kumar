# Modulation Schemes in the PHY Layer: Working and Comparison

## **Overview of Modulation Schemes**

In the PHY (Physical) layer of Wi-Fi standards, modulation schemes are used to encode data onto radio waves for transmission. These schemes involve varying the properties of the carrier signal—such as amplitude, frequency, or phase—to represent digital data. 

### **Common Modulation Techniques**
1. **Amplitude Shift Keying (ASK)**:
   - Encodes data by varying the amplitude of the carrier signal.
   - Simplest modulation, but less efficient and prone to noise interference.

2. **Frequency Shift Keying (FSK)**:
   - Represents data by changing the frequency of the carrier signal.
   - More robust against noise than ASK, but limited in efficiency.

3. **Phase Shift Keying (PSK)**:
   - Encodes data by changing the phase of the carrier signal.
   - Offers higher data rates and better noise resilience compared to ASK and FSK.

4. **Quadrature Amplitude Modulation (QAM)**:
   - Combines amplitude and phase modulation to encode data on two carrier waves simultaneously.
   - Supports higher data rates and is commonly used in modern Wi-Fi standards.

---

## **Comparison of Modulation Schemes Across Wi-Fi Standards**

| Wi-Fi Standard  | Modulation Scheme Used            | Max Data Rate       | Efficiency   | Noise Resilience | Use Case                          |
|------------------|-----------------------------------|---------------------|--------------|------------------|-----------------------------------|
| **802.11b**     | Binary Phase Shift Keying (BPSK), QPSK | Up to 11 Mbps   | Low          | Moderate         | Basic internet access.           |
| **802.11g**     | QPSK, 16-QAM                      | Up to 54 Mbps      | Moderate      | Higher           | Faster browsing and downloads.   |
| **802.11n**     | QPSK, 64-QAM                     | Up to 600 Mbps     | High          | High             | HD streaming, large file transfers. |
| **802.11ac**    | 256-QAM                          | Up to 6.9 Gbps     | Very High     | Very High        | High-bandwidth applications.     |
| **802.11ax (Wi-Fi 6)** | 1024-QAM                    | Up to 9.6 Gbps     | Extremely High | Extremely High   | Efficient usage, IoT, streaming. |

---

### **Key Insights**:
1. **Data Rate Progression**:
   - As Wi-Fi standards evolved, the modulation schemes transitioned to support higher-order QAM (e.g., 256-QAM, 1024-QAM), enabling faster data rates.

2. **Efficiency and Noise Handling**:
   - Higher-order schemes like 1024-QAM are incredibly efficient but require better signal-to-noise ratios (SNR) for reliable communication.

3. **Performance Trade-offs**:
   - Advanced schemes demand high SNR environments (e.g., close proximity to the router or access point).
   - Simpler schemes (like BPSK) work better in noisy or long-range scenarios.

---

## **Conclusion**

Modulation schemes are at the heart of Wi-Fi performance, enabling faster speeds and efficient data transmission. The choice of modulation depends on the specific requirements—whether it's bandwidth, range, or noise resilience. Modern Wi-Fi standards like Wi-Fi 6 leverage advanced modulation (1024-QAM) for unparalleled speed and efficiency.

---

