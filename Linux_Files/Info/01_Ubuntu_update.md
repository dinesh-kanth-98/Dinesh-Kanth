**<div align="center" >About Ubuntu Updates</div>**

### Table of content

- [Update Ubuntu Commands](#update-ubuntu-commands)
- [Brief About Commands](#brief-about-commands)

# Update Ubuntu Commands

```bash
sudo apt update
sudo apt list --upgradable
sudo apt upgrade
sudo apt autoremove
sudo apt clean
```

# Brief About Commands

1. `sudo apt update`:
   - This command updates the package list for your Ubuntu system.
   - When you run it, Ubuntu will check for the latest information about available software packages from the configured repositories.
   - It doesn't install or upgrade any packages; it only updates the list of available packages.

2. `sudo apt list --upgradable`:
   - This command lists the packages that have updates available.
   - It shows the names of packages, their current versions, and the newer versions that are available for upgrade.
   - It helps you identify which packages have updates waiting to be installed.

3. `sudo apt upgrade`:
   - After you've reviewed the list of available updates using the previous command, you can proceed with this one.
   - It upgrades installed packages to their latest available versions.
   - If there are updates available for your packages, this command will download and install them.
   - You may be prompted to confirm the upgrade by typing 'Y' and pressing Enter.

4. `sudo apt autoremove`:
   - This command removes old or unused packages that were installed as dependencies for other packages.
   - It helps to free up disk space by getting rid of packages that are no longer needed.
   - It's a good practice to run this command periodically.

5. `sudo apt clean`:
   - This command cleans up the local repository of retrieved package files (deb files) that are no longer required.
   - It helps to save disk space by removing cached package files.

> The update process ensures that your Ubuntu system has the latest information about available software packages, installs available updates, and removes unnecessary packages. This process is essential for keeping your system secure and up to date.
