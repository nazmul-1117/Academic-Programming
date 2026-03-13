# 1️⃣ Tabular Data Deep Learning (Very good for free GPU)

### Paper idea

Use **Transformer-based models for tabular data** like **TabPFN**.

* TabPFN uses a transformer trained on synthetic datasets to predict tabular tasks quickly without heavy training. ([Wikipedia][1])
* It works well with **small datasets (<10k samples)**. ([Wikipedia][1])

### Possible project

**Title example:**

> “Benchmarking Transformer-based Tabular Models vs Classical ML Methods”

### Implementation

1. Choose datasets:

   * Kaggle tabular datasets (credit scoring, heart disease, diabetes)
2. Compare models:

   * Logistic Regression
   * Random Forest
   * KNN
   * Neural Network
   * TabPFN
3. Evaluate:

   * Accuracy
   * Training time
   * robustness to small datasets

### Why this project is good

✔ easy dataset
✔ small compute
✔ strong research topic

---

# 2️⃣ CNN + Transfer Learning for Medical Image Classification

### Paper idea

Use **transfer learning CNN for medical diagnosis**.

Example project:

> “Pneumonia Detection from Chest X-ray using EfficientNet / ResNet Transfer Learning”

### Implementation

Dataset:

* Chest X-ray dataset (Kaggle)

Models:

* CNN baseline
* Transfer learning (ResNet / EfficientNet)

Possible improvement:

* data augmentation
* ensemble

### Why good

✔ easy dataset
✔ CNN already in your syllabus
✔ many 2024 papers improving this approach

---

# 3️⃣ Hybrid ML + Deep Learning for Time Series

Example research direction:

> Hybrid **KNN + LSTM** or **CNN + LSTM** for anomaly detection in time-series.

A recent work explored **hybrid KNN–LSTM frameworks for smart grid electricity theft detection**. ([projectcentersinchennai.co.in][2])

### Project idea

> “Hybrid ML–Deep Learning Model for Time Series Anomaly Detection”

Dataset ideas:

* electricity consumption dataset
* stock price dataset
* sensor anomaly dataset

Models:

* LSTM
* GRU
* CNN-LSTM
* KNN-LSTM hybrid

### Why good

✔ uses RNN/LSTM from your course
✔ moderate compute

---

# 4️⃣ NLP Project (Small Transformer Fine-Tuning)

Project idea:

> “Fake News Detection using BERT with Traditional ML Comparison”

Steps:

1. dataset: FakeNewsNet or Kaggle fake news dataset
2. models:

   * Naive Bayes
   * Logistic regression
   * LSTM
   * BERT fine-tuning
3. compare performance

### Why good

✔ strong ML + DL comparison
✔ works on free GPU

---

# 5️⃣ K-means + Deep Learning for Image Clustering

Project idea:

> “Unsupervised Image Clustering using CNN Feature Extraction + K-means”

Steps:

1. dataset:

   * CIFAR-10
2. extract features using pretrained CNN
3. cluster using:

   * K-means
   * hierarchical clustering
4. evaluate clustering quality

### Why good

✔ includes **unsupervised learning**
✔ fast training

---

# ⭐ My Top 3 Recommendations for Your Team

Considering **time + GPU limits**:

🥇 **Tabular Transformer vs Classical ML (TabPFN)**\
🥈 **CNN Transfer Learning for Medical Images**\
🥉 **Hybrid CNN-LSTM Time Series Detection**

These are **most realistic for 2–3 months**.

---

# Example Project Workflow

1️⃣ Read **4–6 papers (2024–2026)**\
2️⃣ Implement baseline models\
3️⃣ Implement paper model\
4️⃣ Compare performance\
5️⃣ Improve or analyze limitations

Deliverables:

* code
* report
* results
* paper review