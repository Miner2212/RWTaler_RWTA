Quick Docker image for rwtalerd
---------------------------

Build docker image:
   
    docker/build.sh

Push docker image:

    docker/push.sh

Pull rwtalercore/rwtaler:latest from docker hub  at [rwtaler-dockerhub](https://hub.docker.com/r/rwtalercore/rwtaler/)

    sudo docker pull rwtalercore/rwtaler
    
Run docker image

    sudo docker run rwtalercore/rwtaler

Build docker for rwtalerd
----------
A Docker configuration with rwtalerd node by default.

    sudo apt install apt-transport-https ca-certificates curl software-properties-common; curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -; sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"; sudo apt-get update; sudo apt install docker-ce   
---------------------------------------------------        
    
    mkdir rwtaler-mounted-data
    docker run --name rwtaler -d \
     --env 'SPDR_RPCUSER=rpciser' \
     --env 'SPDR_RPCPASSWORD=rpcpassword' \
     --env 'SPDR_TXINDEX=1' \
     --volume ~/rwtaler-mounted-data:~/.rwtaler \
     -p 53616:53616 \
     --publish 53616:53616 \
     rwtalercore/rwtaler
----------------------------------------------------
Logs

    docker logs -f rwtaler

----------------------------------------------------

## Configuration

Set your `rwtaler.conf` file can be placed in the `rwtaler-mounted data` dir.
Otherwise, a default `rwtaler.conf` file will be automatically generated based
on environment variables passed to the container:

| name | default |
| ---- | ------- |
| BTC_RPCUSER | rpcuser |
| BTC_RPCPASSWORD | rpcpassword |
| BTC_RPCPORT | 53616 |
| BTC_RPCALLOWIP | ::/0 |
| BTC_RPCCLIENTTIMEOUT | 30 |
| BTC_DISABLEWALLET | 1 |
| BTC_TXINDEX | 0 |
| BTC_TESTNET | 0 |
| BTC_DBCACHE | 0 |
| BTC_ZMQPUBHASHTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBHASHBLOCK | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWBLOCK | tcp://0.0.0.0:28333 |


## Daemonizing

If you're daemonizing is to use Docker's 
[Daemonizing](https://docs.docker.com/config/containers/start-containers-automatically/#use-a-restart-policy),
but if you're insistent on using systemd, you could do something like

```
$ cat /etc/systemd/system/rwtalerd.service

# rwtalerd.service #######################################################################
[Unit]
Description=RWTaler
After=docker.service
Requires=docker.service

[Service]
ExecStartPre=-/usr/bin/docker kill rwtaler
ExecStartPre=-/usr/bin/docker rm rwtaler
ExecStartPre=/usr/bin/docker pull rwtalercore/rwtaler
ExecStart=/usr/bin/docker run \
    --name rwtaler \
    -p 53616:53616 \
    -p 53616:53616 \
    -v /data/rwtalerd:/root/.rwtaler \
    rwtalercore/rwtaler
ExecStop=/usr/bin/docker stop rwtaler
```
