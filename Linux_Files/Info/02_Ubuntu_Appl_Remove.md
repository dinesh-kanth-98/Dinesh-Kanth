# Remove An App From Ubuntu

1. **Open a Terminal**:
   You can open a terminal by searching for "Terminal" in the Ubuntu Dash or by pressing `Ctrl + Alt + T` on your keyboard.

2. **Uninstall the Application**:
   To uninstall an application, use the `apt` package manager along with the `remove` option. Replace `package-name` with the actual name of the package you want to remove.

   ```bash
   sudo apt remove package-name
   ```

   For example, if you want to remove the application "example-app," you would run:

   ```bash
   sudo apt remove example-app
   ```

3. **Autoremove (Optional)**:
   After uninstalling an application, you can use the `autoremove` option to remove any obsolete packages (dependencies that are no longer needed). This helps keep your system clean.

   ```bash
   sudo apt autoremove
   ```

4. **Purge (Optional)**:
   If you want to remove the application and its configuration files, you can use the `purge` option instead of `remove`. This is useful if you want to completely remove all traces of the application.

   ```bash
   sudo apt purge package-name
   ```

   For example:

   ```bash
   sudo apt purge example-app
   ```

5. **Clean (Optional)**:
   You can also use the `clean` option to remove downloaded package files that are no longer needed.

   ```bash
   sudo apt clean
   ```

Now, the application should be removed from your system.

> Please note that it's essential to be cautious when using the `purge` option, as it will remove configuration files. If you're not sure whether you want to keep the configuration files or not, you can start with the `remove` option.
