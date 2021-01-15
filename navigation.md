# Biao

[I am](index.md)

[Kernel]()

  * [OverView](Kernel/OverView.md)
  * [PCB](Kernel/PCB.md)
  * [process](Kernel/process.md)
  * [Sched](Kernel/Sched.md)
  - - - -
  * # memory
  * [slab](Kernel/slab.md)
  * [min_free_kbytes](Kernel/mem/min_free_kbytes.md)
  * [malloc](Kernel/mem/malloc.md)


[Driver]()

  * [OverView](Driver/OverView.md)
  * [WIFI&BLE](Driver/WIFI_BT.md)
  * [PCIe](Driver/PCIe.md)
  * [SDIO](Driver/SDIO.md)
  * [PM](Driver/PM.md)
  - - - -
  * # USB
  * [USB](Driver/USB/USB.md)
  * [USB_Serial](Driver/USB/USB_Serial.md)
  * [USB标准请求](Driver/USB/UsbRequest.md)
  * [USB共享网络](Driver/USB/USB_Share_Net_With_Host.md)
  - - - -
  * # SDIO
  * [SDIO](Driver/SDIO/SDIO.md)
  * [mmc](Driver/SDIO/mmcSD.md)

[LinuxMisc]()

  * [misc](MISC/misc.md)
  * [Signal](MISC/Signal.md)
  - - - -
  * # Advanced
  * [everyday_cmd](MISC/everydataCMD.md)


[LinuxService]()

  * [DBus](DebianLinux/DBus.md)
  * [Supervisor](DebianLinux/Supervisor.md)
  * [Systemd](DebianLinux/Systemd.md)
  * [SystemAccount](DebianLinux/UserManagement.md)

[Release]()

  * [OverView](LinuxRelease/OverView.md)
  * [busybox](LinuxRelease/busybox.md)
  * [buildroot](LinuxRelease/buildroot.md)
  * [OpenWrt](LinuxRelease/OpenWrt.md)
  * [Yocto](LinuxRelease/Yocto.md)
  * [Ubuntu](LinuxRelease/Ubuntu.md)
  * [Android](LinuxRelease/Android.md)
  - - - -
  * # Advanced
  * [Lichee](LinuxRelease/licheezero.md)
  * [Khadas](LinuxRelease/Khadas.md)
  * [210](LinuxRelease/210.md)
  * [CM4](LinuxRelease/Raspberry.CM4.md)
  * [IMX8](LinuxRelease/IMX8_Android9_Bringup.md)
  - - - -
  * # Virtual Machine
  * [QEMU_Vexpress](LinuxRelease/Vexpress.md)
  * [QEMU_Vexpress_RT-Thread](LinuxRelease/Vexpress_RT-Thread.md)
  * [MenuOS](LinuxRelease/LinuxRelease/menu/MenuOS.md)
  * [RunningLinuxKernel](LinuxRelease/running/RunningLinuxKernel.md)


[Shell]()

  * [Shell](SHELL/linuxshell.md)
  * [winbat](SHELL/winbat.md)

[BringUp]()

  * [VimIDE](BringUp/VimIDE.md)
  * [WindowsTerminal](BringUp/WindowsTerminal.md)
  * [](BringUp/.md)
  * [Docker](BringUp/docker.md)

[Qt]()

  * [Qt](Qt/Qt.md)
  * [QtUsb](Qt/QtUSB.md)
  * [FAQ](Qt/FAQs.md)

[Others]()

  * [HareWare](Others/Hardware.md)
  * [Something](Others/Something.md)
  * [winbat](Others/SystemV.md)
  - - - -
   * # Python
   * [basic](Others/Python/pybasic.md)
   * [examples](Others/Python/useful_example.md)
  - - - -
  * # Web
  * [myBlog](Otherss/Web/myBlog.md)
  * [Web](Otherss/Web/OverView.md)
  * [html](Others/Web/HTML.md)
  * [CSS](Others/Web/CSS.md)
  * [JS](Others/Web/JS.md)
  * [php](Others/Web/PHP.md)
  - - - -
  * # Related
  * [httpServer](Others/Web/pyHttpServer.md)
  * [mdWiki](Others/Web/mdWiki.md)
  - - - -
  * # myBlogs
  * [gdb编译](Others/myBlogs/2020_11_29_QEMU_gdb.md)
  * [Wine](Others/Wine.md)

[Links]()

  * [NetWork](links/network.md)
  * [Quectel](links/quectel.md)
  * [Khadas](links/KhadasDoc.md)

[gimmick:theme (inverse: false)](spacelab)

[gimmick:ThemeChooser](Change theme)

[gimmick:forkmeongithub](http://github.com/QuectelWB/myStudy/)

<!-- counter pixel for counting visitors -->
<!-- <img src="http://stats.markdown.io/mdwiki_info.gif" style="display:none;"/> -->

<script>
$(document).ready(function() {
  $.md.stage('all_ready').subscribe(function (done) {
    var warning="";
    warning+="ATTENTION: This is the unstable MDwiki website. For documentation of the latest stable ";
    warning+="MDwiki please see <a href='http://www.mdwiki.info'>the stable documentation.</a>";

    $('#md-content').prepend($('<div class="alert alert-danger">' + warning + '</div>'));
    done();
  });
});
</script>

<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-44627253-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>

