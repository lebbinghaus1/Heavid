MySQL Connector/C++ files should me moved here for use with Heavid. You can download MySQL Connector/C++ here: https://dev.mysql.com/downloads/connector/cpp/

This should be done such that the directories are as follows:
	~/mysql-connector-cpp/include/cppconn
	~/mysql-connector-cpp/lib/

This is critical for newer versions of Connector/C++ which host the legacy files used for Heavid in the jdbc subfolder.

Alternatively, if you are using a Linux/GNU Operating System, you can leave this directory empty and install the library to /usr/lib and /usr/include 