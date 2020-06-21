[Unit]
Description=RWTA's distributed currency daemon
After=network.target

[Service]
User=rwtaler
Group=rwtaler

Type=forking
PIDFile=/var/lib/rwtalerd/rwtalerd.pid

ExecStart=/usr/bin/rwtalerd -daemon -pid=/var/lib/rwtalerd/rwtalerd.pid \
          -conf=/etc/rwtaler/rwtaler.conf -datadir=/var/lib/rwtalerd

ExecStop=-/usr/bin/rwtaler-cli -conf=/etc/rwtaler/rwtaler.conf \
         -datadir=/var/lib/rwtalerd stop

Restart=always
PrivateTmp=true
TimeoutStopSec=60s
TimeoutStartSec=2s
StartLimitInterval=120s
StartLimitBurst=5

[Install]
WantedBy=multi-user.target
