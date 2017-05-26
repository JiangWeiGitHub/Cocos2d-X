# Cocos2d-X

### Information
+ Version: 3.14.1
+ [*download path*](http://www.cocos2d-x.org/filedown/cocos2d-x-3.14.1.zip)
+ Host: **Ubuntu 16.04.1 Desktop amd64**
+ [Official Site](http://cocos2d-x.org/)
+ [Official Github](https://github.com/cocos2d/cocos2d-x)
+ [Cocos command-line tool](http://cocos2d-x.org/docs/editors_and_tools/cocosCLTool/)
+ [Samples](https://github.com/cocos2d/cocos2d-x-samples)
+ [**Good Commentary**](http://www.cnblogs.com/mmidd/p/3709536.html)

### Run Test Sample
+ download
+ unzip
+ enter into root of this unzip folder
+ run command like below:
```
  sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/local/lib/
  sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/local/lib/
  ln -s libfmod.so libfmod.so.6
```
PS: [*because of this*](http://discuss.cocos2d-x.org/t/error-while-building-for-linux-libfmod-so-6/26553)

+ cd `./build`
+ run `./install-deps-linux.sh`
+ run `cmake ..`
+ run `make`
+ run test sample like `./bin/cpp-tests/cpp-tests`

### Create A New Project
+ Setting up cocos
  
  `./setup.py`
  
+ Using Sample

  `cocos new <game name> -p <package identifier> -l <language> -d <location>`
  
  Like: `cocos new helloWorld -p helloWorld -l cpp -d ./`
  
+ Compiling Sample

  `cocos compile -s <path to your project> -p <platform> -m <mode> -o <output directory>`
  
  Like: `cocos compile . -p linux -m release`

+ Add Files

  ...


### Running Existed Project (inelegant)
+ Create a new empty project

  PS: only for get cocos's lib

+ Clone project from `github`

+ Compiling
