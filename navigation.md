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
  * [USB](Driver/USB.md)
  * [WIFI&BLE](Driver/WIFI_BT.md)
  * [WIFI&BLE](Driver/PM.md)

[LinuxMisc]()

  * [misc](MISC/misc.md)
  * [Shell](MISC/linuxshell.md)
  * [Signal](MISC/Signal.md)
  - - - -
  * # Advanced
  * [每天一个新命令](MISC/everydataCMD.md)


[NetWork](network.md)

[Quectel](quectel.md)


[Web]()

  * [OverView](Web/OverView.md)
  * [html](Web/HTML.md)
  * [CSS](Web/CSS.md)
  * [JS](Web/JS.md)
  * [JQuery](Web/JQuery.md)
  * [bootstrap](Web/BootStrap.md)
  * [php](Web/PHP.md)
  - - - -
  * # Related
  * [httpServer](Web/pyHttpServer.md)
  * [mdWiki](Web/mdWiki.md)

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
  * [QEMU_Vexpress](LinuxRelease/Vexpress.md)
  * [QEMU_Vexpress_RT-Thread](LinuxRelease/Vexpress_RT-Thread.md)

[Others]()

  * [Qt](Others/Qt.md)
  * [winbat](Others/winbat.md)
  * [winbat](Others/SystemV.md)
  - - - -
   * # Pthon
   * [basic](Others/Python/pybasic.md)
   * [examples](Others/Python/useful_example.md)


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

