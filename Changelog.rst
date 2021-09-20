1.0
~~~

Added
.....

**xbutil/xbmgmt**

* Added ``xball`` helper script to execute a common set of utility commands (e.g., ``xbutil`` & ``xbmgmt``) across a filtered set of devices.  More information can be found using ``--help`` or in the XRT documents.
* Auto-selecting a device if only one device exits.  If the option ``--device`` or ``-d`` is specified and there is only one device installed, it will be automatically selected and used.
* All failing operations will now return an error code.  Note: An error will also be returned if there are validation failures.
* Improved error reporting.
* Legacy commands have been deprecated.
* Various report output improvements.
* ``xbutil configure`` *root* level command introduced.  Added ``host_mem`` and ``p2p``.
* ``--force`` option support for all operations
* ``xbutil validate`` now supports alternative platform validation directories

* test2

Removed
.......
