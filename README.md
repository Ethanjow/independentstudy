# Environment Setup Guide (Linux)

This guide explains how to set up the required Python environment on a **Linux** system using one of the following methods:

- `venv` with `pyvenv.cfg` and `requirements.txt`
- `conda` with `environment.yml`

---

## 📁 Directory Structure

Your environment directory should contain the following files:

```
project/
├── requirements.txt
├── pyvenv.cfg
└── environment.yml
```

---

## 🔧 Option 1: Using Python `venv` (with `requirements.txt` and `pyvenv.cfg`)

### 1. Create a Virtual Environment

```bash
python3 -m venv venv
```

> This will generate a `venv/` directory containing the environment and a `pyvenv.cfg` file.

### 2. Activate the Virtual Environment

```bash
source venv/bin/activate
```

> Your shell prompt should change to show the virtual environment is active.

### 3. Install Dependencies

```bash
pip install -r requirements.txt
```

### ✅ You're done!

Your Python environment is now set up with the required packages.

---

## 🧪 Option 2: Using Conda (with `environment.yml`)

If you're using [Anaconda](https://www.anaconda.com/) or [Miniconda](https://docs.conda.io/en/latest/miniconda.html):

### 1. Create the Environment

```bash
conda env create -f environment.yml
```

This will create a new environment with the name and dependencies specified in the `environment.yml` file.

### 2. Activate the Environment

```bash
conda activate your-env-name
```

Replace `your-env-name` with the name specified in `environment.yml`.

---

## 🔁 Switching Between Environments

- To deactivate a `venv` environment:
  ```bash
  deactivate
  ```

- To deactivate a `conda` environment:
  ```bash
  conda deactivate
  ```

---

## 🧹 Optional Cleanup

To remove environments:

- `venv`:
  ```bash
  rm -rf venv/
  ```

- `conda`:
  ```bash
  conda env remove --name your-env-name
  ```

---

## ❓ Troubleshooting

- If you get `command not found: python3`, make sure Python 3 is installed.
- Use `which python` or `which pip` to verify you're using the versions from the activated environment.

---

README DONE BY CHATGPT:
https://chatgpt.com/c/68379552-d18c-8002-9615-d3b2d5b70f0f 
