# Biao

[I am](index.md)


[Kernel]()

  * [PCB](Kernel/PCB.md)
  * [slab](Kernel/slab.md)
  * [FAQ](faq.md)
  - - - -
  * # Advanced
  * [Customizing](customizing.md)


[Driver]()

  * [winos](Driver/winos.md)
  * [winbat](Driver/winbat.md)
  * [FAQ](Driver/.md)
  - - - -
  * # Advanced
  * [FAQ](Driver.md)

[LinuxMisc]()

  * [misc](MISC/misc.md)
  * [Shell](MISC/linuxshell.md)
  * [Signal](MISC/Signal.md)
  - - - -
  * # Advanced
  * [每天一个新命令](MISC/everydataCMD.md)


[HardWare](hd.md)

[NetWork](network.md)

[Quectel](quectel.md)

[Python]()

  * [basic](Python/pybasic.md)
  * [examples](Python/useful_example.md)
  - - - -
  * # Advanced
  * [Notes](Notes.md)


[Web]()

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

  * [busybox](LinuxRelease/busybox.md)
  * [buildroot](LinuxRelease/buildroot.md)
  * [OpenWrt](LinuxRelease/OpenWrt.md)
  * [Yocto](LinuxRelease/Yocto.md)
  * [Ubuntu](LinuxRelease/Ubuntu.md)
  - - - -
  * # Advanced
  * [Android](NLinuxRelease/Android.md)


[Others]()

  * [Qt](Others/Qt.md)
  * [winbat](Others/winbat.md)
  * [](Others/)
  - - - -
  * # Advanced
  * [Customizing](customizing.md)

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

