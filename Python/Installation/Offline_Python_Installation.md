Certainly, here's the modified step-by-step guide with the download link for the Python source code as the first point:

**1. Download Python Source Code:**

   First, download the Python source code from the official Python website. Visit the Python downloads page to find the latest version:

   [Python Downloads](https://www.python.org/downloads/)

   Once you've downloaded the source code archive (usually in a tar.xz or tar.gz format), proceed with the following steps:

**2. Extract the Python Source Code:**
   
   Navigate to the directory where you have downloaded the Python source code archive, and then extract it using the `tar` command:

   ```bash
   tar -xvf Python-3.11.1.tar.xz
   ```

**3. Navigate to the Python Source Directory:**

   After extracting the source code, navigate to the directory containing the Python source code:

   ```bash
   cd Python-3.11.1
   ```

**4. Configure Python:**

   Run the `configure` script to prepare the Python build:

   ```bash
   ./configure
   ```

   This script will check your system for dependencies and configure the build settings.

**5. Build Python:**

   Next, use the `make` command to build Python:

   ```bash
   make
   ```

   This step may take some time as it compiles Python from the source code.

**6. Install Python:**

   Finally, use `sudo make install` to install Python system-wide. This will copy the Python binaries, libraries, and other files to their appropriate locations on your system:

   ```bash
   sudo make install
   ```

   After this step, Python should be installed on your system, and you can use it by running `python3.11` (or simply `python3`) in the terminal. To verify the installation, run:

   ```bash
   python3 --version
   ```

This process will install Python 3.11.1 from source on your system. Keep in mind that building Python from source may require certain development tools and libraries to be installed on your system. If you encounter any errors or missing dependencies during the configure or make steps, you may need to install those dependencies before proceeding. 
