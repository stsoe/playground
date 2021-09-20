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
* ``xbutil configure`` *root* level command introduced.  Added ``host_mem`` and ``p2p`` as commands to configure.
* ``--force`` option support for all operations
* ``xbutil validate`` now supports alternative platform validation directories

**xclbin**

* ``PARTITION_METADATA`` schema updated to support pcie bars.
* ``ACCEL_DEADLOCK_DETECTOR`` enum for Debug IP Layout.

**XRT native APIs**

* ``xrt::aie`` and ``xrt::graph`` moved from experimental to mature and are now available from ``include/xrt/`` folder. 
* Added C++ support for xrt::aie APIs.
* Throw an exception if xrt::kernel is constructed with an ``AP_CTRL_NONE`` kernel.  Use ``xrt::ip`` to control custom IPs.
* HLS mailbox support via experimental API ``include/experimental/xrt_mailbox.h``.  See ``tests/xrt/mailbox`` for an example.
* HLS kernel reset support using ``xrt::run::abort()``.  If a run is aborted without kernel support for sw reset, the board itself will require a reset. 
* Fixed bug in ``xrt::run::wait`` where specified timeout was ignored.
* Added new ``xrt::device::get_info`` parameters and guaranteed format of return type with new versions of XRT.

**Other changes**

* Added missing ``:`` separator in regex when matching the kernel name specified to ``clCreateKernel`` and ``xrt::kernel``.  Without the separator, matching would fail when a specified kernel name is a substring of another kernel name.  The default regex is now ``"(kernelname):(.*)"``.
* Fix register read and write in HW emulation to use the CU index ordering as rest of XRT.
* Fix bugs related to kernel address range size (1) support custom address range size, (2) trap error when writing outside the kernel address range.
* Support enabled for ``RHEL 8.4`` and ``buntu 20.04.2`` OS
* zocl memory manager improvements to support any sptag.

Removed
.......

* xclExecBufWithWaitList() API is deprecated and will be removed in future release
* Support is removed for  ``RHEL/Centos 7.6`` , ``7.7``  & ``Ubuntu 16.04``
