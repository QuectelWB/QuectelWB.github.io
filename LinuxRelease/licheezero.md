LicheePiZero
======

|Referrence|
---
| [http://zero.lichee.pro/](http://zero.lichee.pro/)|
| [https://github.com/Lichee-Pi](https://github.com/Lichee-Pi) |


docker
----

	sudo groupadd docker
	sudo gpasswd -a ${your_user_name} docker
	sudo service docker restart
	newgrp - docker
	docker pull zepan/licheepi
	docker run -d -p 6666:22 zepan/licheepi /usr/sbin/sshd -D









:)
