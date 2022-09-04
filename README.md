diag-stamp-js
=============

[diag_logcat](https://github.com/lrh2000/diag_logcat) record Qualcomm baseband's logs in `.dlog` files. The baseband processor's timestamps are included, however, they are not usable at all, since the baseband processor's clock has not been synchronized with the application processor's. To step forward, [diag_logcat](https://github.com/lrh2000/diag_logcat) also record the timestamp at with the application processor first sees each baseband log, in the `.tlog` files. This tool `diag-stamp-js` tries to calculate the time difference between the application processor and baseband processor's clocks, given both `.dlog` file and its corresponding `.tlog` file, in a best-effort manner.

Usage
-----

 1. Download dependencies and build
```
npm install
```
 2. Invoke the function to calculate the time difference (the application processor's timestamp $t_{app}$ minus the baseband processor's timestamp $t_{bb}$, in nanoseconds)
```js
const calcDiagStampDiff = require('diag-stamp');
console.log('t_{app} - t_{bb} =', calcDiagStampDiff('example.dlog', 'example.tlog'), 'ns');
```
