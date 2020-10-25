关于 MDwiki
=========

MDwiki 是一个 __完全用 HTML5/Javascript 构建、100% 运行在客户端__  的 CMS/Wiki 引擎。不需要安装特别的软件 或 需要服务器端进程。只需要上传 内置 MDwiki 引擎的 `mdwiki.html` 文件，放到你的 MarkDown 文件的同一目录，就一切就绪了！

Note: 你正在浏览的网站 就是用 MDwiki 实现的，并托管在 [GitHub Pages](http://pages.github.com/) 服务上。[http://mdwiki.info](http://mdwiki.info) 重定向到此。

[gimmick:twitterfollow](timodoerr)


主要特性
----

  * 完全用 JavaScript、HTML 5 构建，__不需要任何本地或远程的安装__
  * 用 [Markdown][markdown] 作为它的输入标记语言
  * 构建于 [jQuery][jQuery] 和 [Bootstrap3][bootstrap] 之上，以便跨浏览器工作，同时拥有 响应式布局
  * 用特殊的 [_Gimmicks_][gimmicks] 来扩展 MarkDown，来添加富客户端功能，比如 凭借 [hightlight.js][highlightjs] 实现语法高亮、[GitHub Gists][gists] 或 用 [Google Maps][maps] 展示地理数据
  * 凭借 BootStrap 的通用性实现主题化，支持来自 [BootSwatch](http://www.bootswatch.com) 的所有主题


基本要求
----

* 网页空间（或一个能托管静态文件的 Web 服务器）
* 任何现代的网页浏览器
* [mdwiki.html][download] 文件


它是如何工作的？
--------

只需把从 [下载页][download] 获得的 `mdwiki.html` 和你的 MarkDown 文件一起丢到一个网页空间的某处。你可以在 Hash 符 `#!` 后传任何 URL 给 MDwiki（相对于 `mdwiki.html` 文件）：

    http://www.example.com/mdwiki.html#!myfile.md

如果你把 `mdwiki.html` 重命名为 `index.html`，在大多数 Web 服务器上你可以省略文件名：

    http://www.example.com/#!myfile.md

MDwiki 会默认在 `index.html` 同级目录中加载一个名为 `index.md` 的文件，所以若你使用一个 `index.md` 文件作为入口点，你就只需要输入你的域名：

    http://example.com/

Note: MDwiki 有比规范的 MarkDown 更多的特性，详见 [快速入门教程][quickstart]。

- - - -

技术鸣谢
----

若不是因为那些伟大的软件，MDwiki 将不会存在：

  * [marked][marked]
  * [jQuery][jQuery]
  * [Bootstrap][bootstrap]
  * [Bootswatch][bootswatch]
  * [colorbox][colorbox]
  * [highlightjs][highlightjs]

MDwiki 由 Timo Dörr 创造。关注我来获得 MDwiki 的更新！[关注 @timodoerr](http://www.twitter.com/timodoerr).

可爱小猫的图片 由 伟大的 [placekitten.com] 服务提供。

  [download]: download.md
  [quickstart]: quickstart.md
  [gimmicks]: gimmicks.md

  [markdown]: http://daringfireball.net/projects/markdown/
  [jQuery]: http://www.jquery.org
  [bootstrap]: http://www.getbootstrap.com
  [bootswatch]: http://www.bootswatch.com
  [marked]: https://github.com/chjj/marked
  [colorbox]: http://www.jacklmoore.com/colorbox/
  [gists]: https://gist.github.com/
  [maps]: http://maps.google.com/
  [highlightjs]: https://highlightjs.org/
  [placekitten.com]: http://www.placekitten.com/

授权协议
----

MDwiki 在 [GNU GPLv3 附加条款适用][license] 许可证下授权。

  [license]: https://github.com/Dynalon/mdwiki/blob/master/LICENSE.txt