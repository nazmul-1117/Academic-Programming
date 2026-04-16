
# Simple Neural Network from Scratch (NumPy)

This project implements a basic feedforward neural network with one hidden layer and backpropagation using pure Python (and NumPy for activation function).

It is designed for educational purposes to demonstrate how forward propagation, error calculation, and weight updates work internally in a neural network.

---

## 📘 Course Information

* **Course:** Machine Learning
* **Course Code:** CSE 411
* **Section:** 223_D1
* **Institution:** KSA-II

---

## 🧠 Model Overview

The network consists of:

* **Input Layer:** 2 features (`x[0]`, `x[1]`)
* **Hidden Layer:** 2 neurons (`y3`, `y4`)
* **Output Layer:** 1 neuron (`y5`)
* **Activation Function:** Sigmoid

### Architecture Flow

```
Inputs → Hidden Layer → Output Layer → Prediction
   x1,x2 → y3,y4 → y5
```

---

## ⚙️ Features

* Forward propagation using weighted sums
* Sigmoid activation function
* Simple error calculation (target − prediction)
* Backpropagation with manual gradient computation
* Weight updates using gradient descent logic

---

## 🧮 Forward Propagation

The network computes:

* Hidden layer activations:

  * `a3 = x1*w0 + x2*w2`
  * `a4 = x1*w1 + x2*w3`
* Output layer:

  * `a5 = y3*w4 + y4*w5`

Then applies sigmoid activation:

```
sigmoid(x) = 1 / (1 + e^(-x))
```

---

## 🔁 Backpropagation

The model computes deltas for each neuron:

* Output layer error term (`delta_5`)
* Hidden layer error terms (`delta_3`, `delta_4`)

Weights are updated using:

* Output weights:
  `w += delta_5 * hidden_output`

* Input weights:
  `w += delta_hidden * input_value`

---

## 📦 Requirements

* Python 3.7+
* NumPy

Install dependencies:

```bash
pip install numpy
```

---

## 🚀 How to Run

Example usage:

```python
import numpy as np
from network import Network

x = [0.5, 0.8]
weights = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6]

nn = Network(x, weights, target_output=0.5)

output = nn.forward_pass()
print("Output:", output)

nn.back_propagation()
nn.print_weights()
```

---

## 📌 Notes

* This implementation is **for learning purposes only**
* No vectorization or optimization techniques are used
* Intended to help understand the math behind neural networks

---

## 📚 Learning Outcomes

By studying this project, you will understand:

* How forward propagation works internally
* How sigmoid activation affects outputs
* How backpropagation computes gradients
* How weights are updated manually in a neural network

---

## 🏫 Academic Use

This project is submitted as part of:

**Machine Learning (CSE 411), Section 223_D1, KSA-II**

---