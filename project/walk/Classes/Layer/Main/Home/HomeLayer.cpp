#include "./HomeLayer.h"

namespace jiangweigithub {

  cocos2d::Layer* HomeLayer::getHomeLayer()
  {
    auto tmp = HomeLayer::create();

    return tmp;
  }

  bool HomeLayer::init()
  {
    if(!Layer::init())
    {
      return false;
    }

    // clean keyboardName Cache
    if(this->_keyboardNameCache.size() != 0)
    {
      while(this->_keyboardNameCache.empty() == false)
      {
        this->_keyboardNameCache.pop();
      }
    }

    // get view size
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    // create hero with physicsBody
    leaderSprite = cocos2d::Sprite::create();    
    cocos2d::PhysicsBody* physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(30, 20), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, cocos2d::Vec2(15, 10));
    physicsBody->setDynamic(false);
    leaderSprite->setPhysicsBody(physicsBody);
    leaderSprite->getPhysicsBody()->setCategoryBitmask(heroMask);
    leaderSprite->getPhysicsBody()->setContactTestBitmask(heroMask | wallMask);
    leaderSprite->getPhysicsBody()->setCollisionBitmask(0x00);
    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));

    // create background
    auto homeTitle = MainSprite::getHomeTitle();
    auto tileMapSprite = MainSprite::getTileMapSprite();
    auto mapSpriteSize = tileMapSprite->getContentSize();
    auto homeTitleSpriteSize = homeTitle->getContentSize();

    tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    leaderSprite->setPosition(cocos2d::Vec2(this->_heroPositionX, this->_heroPositionY));
    leaderSprite->setAnchorPoint(cocos2d::Vec2(0, 0));


    auto aaa = cocos2d::TMXTiledMap::create("homeBackground.tmx");
    auto bbb = cocos2d::TMXTiledMap::create("homeFront.tmx");
    auto ccc = cocos2d::TMXTiledMap::create("homeShadow.tmx");
    aaa->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    bbb->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    ccc->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));

    cocos2d::DrawNode* drawNode = cocos2d::DrawNode::create();

    cocos2d::Vec2 point[4];
    point[0] = cocos2d::Vec2(20, 25);
    point[1] = cocos2d::Vec2(1260, 25);
    point[2] = cocos2d::Vec2(1260, 210);
    point[3] = cocos2d::Vec2(20, 210);
    drawNode->drawPolygon(point, 4, cocos2d::Color4F(66/255.0f, 66/255.0f, 66/255.0f, 0.5f), 1, cocos2d::Color4F(243/255.0f, 198/255.0f, 108/255.0f, 0.7f));    
    drawNode->setPosition(cocos2d::Vec2(0,0));
    this->addChild(drawNode, 100);

    auto fff =  cocos2d::Sprite::create("golderFlower.png");
    fff->setScale(0.6);
    fff->setOpacity(235);
    fff->setAnchorPoint(cocos2d::Vec2(0, 0));
    fff->setRotation(180);
    fff->setPosition(cocos2d::Vec2(1265, 225));
    this->addChild(fff, 101);

    auto ggg =  cocos2d::Sprite::create("golderFlower.png");
    ggg->setScale(0.6);
    ggg->setOpacity(235);
    ggg->setAnchorPoint(cocos2d::Vec2(0, 0));
    ggg->setPosition(cocos2d::Vec2(15, 15));
    this->addChild(ggg, 101);

    auto ddd =  cocos2d::Sprite::create("avatar.png");
    ddd->setScale(0.9);
    ddd->setAnchorPoint(cocos2d::Vec2(0, 0));
    ddd->setPosition(cocos2d::Vec2(21, 26));
    this->addChild(ddd, 100);

    _firstLine = cocos2d::Label::createWithTTF("Today is a good day.", "fonts/arial.ttf", 22);
    _firstLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _firstLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _firstLine->enableShadow();
    _firstLine->setPosition(cocos2d::Vec2(350, 125));
    this->addChild(_firstLine, 102);

    _secondLine = cocos2d::Label::createWithTTF("I've watched a good movie this evening!", "fonts/arial.ttf", 22);
    _secondLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _secondLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _secondLine->enableShadow();
    _secondLine->setPosition(cocos2d::Vec2(350, 90));
    this->addChild(_secondLine, 102);

    _thirdLine = cocos2d::Label::createWithTTF("Have a good dream, stranger.", "fonts/arial.ttf", 22);
    _thirdLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _thirdLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _thirdLine->enableShadow();
    _thirdLine->setPosition(cocos2d::Vec2(350, 55));
    this->addChild(_thirdLine, 102);

    _nameLine = cocos2d::Label::createWithTTF("Hero:", "fonts/arial.ttf", 26);
    _nameLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _nameLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _nameLine->enableShadow();
    _nameLine->setPosition(cocos2d::Vec2(320, 165));
    this->addChild(_nameLine, 102);


    auto nextString = cocos2d::MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HomeLayer::_nextStringCallback, this));
    
    nextString->setPosition(cocos2d::Vec2(1200, 60));

    auto menu = cocos2d::Menu::create(nextString, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu, 103);


    // add to the layer
    this->addChild(aaa, -10);
    this->addChild(homeTitle, 0);
    this->addChild(ccc, 3);
    this->addChild(leaderSprite, 5);
    this->addChild(bbb, 10);


    // add keyboard listener
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HomeLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HomeLayer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // get background barrier
    cocos2d::TMXTiledMap* map = cocos2d::TMXTiledMap::create("homePath.tmx");
    auto objectGroup = map->getObjectGroup("path");
    auto objects = objectGroup->getObjects();

    for (auto object: objects)
    {
      auto dic= object.asValueMap();
      auto objectX = dic.at("x").asFloat();
      auto objectY = dic.at("y").asFloat();        

      auto pointsVector = dic.at("polylinePoints").asValueVector();
      auto size = pointsVector.size();

      cocos2d::Vec2 verts[size] = {};
      int counter = 0;

      if (size>0)
      {
        for (auto pointValue:pointsVector)
        {
          auto dicp = pointValue.asValueMap();
          auto x  = dicp.at("x").asFloat();
          auto y  = -dicp.at("y").asFloat();

          verts[counter].setPoint(x + (1280 - 960) / 2, y + (720 - 480) / 2 + 480);
          counter++;
        }
      }

      cocos2d::Sprite* edgeSpace=cocos2d::Sprite::create(); 
      cocos2d::PhysicsBody* boundBody=cocos2d::PhysicsBody::createEdgePolygon(verts, counter, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 1);

      edgeSpace->setPhysicsBody(boundBody); 
      edgeSpace->setPosition(objectX , objectY - 480);
      this->addChild(edgeSpace, 0); 

      edgeSpace->getPhysicsBody()->setCategoryBitmask(wallMask);
      edgeSpace->getPhysicsBody()->setContactTestBitmask(heroMask | wallMask);
      edgeSpace->getPhysicsBody()->setCollisionBitmask(0x00);
    }

    // add physics listener
    cocos2d::EventListenerPhysicsContact* contactListener = cocos2d::EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HomeLayer::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HomeLayer::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    // enable frame update
    this->scheduleUpdate();

    return true;
  }

  void HomeLayer::update(float delta)
  {
    if(this->_keyboardNameCache.empty() == false)
    {
      if(this->_keyboardNameCache.top().compare("TOP") == 0)
      {
        if(this->_durationTop == true)
        {
          keyManager->pressTop(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }        
      }
      if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
      {
        if(this->_durationBottom == true)
        {
          keyManager->pressBottom(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        } 
      }
      if(this->_keyboardNameCache.top().compare("LEFT") == 0)
      {
        if(this->_durationLeft == true)
        {
          keyManager->pressLeft(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }
      }
      if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
      {
        if(this->_durationRight == true)
        {
          keyManager->pressRight(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }
      }
    }
  }

  void HomeLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->_durationTop = true;
        this->_keyboardNameCache.push("TOP");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
        break;
        
      case 29:
        // bottom
        this->_durationBottom = true;
        this->_keyboardNameCache.push("BOTTOM");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
        break;
      case 26:
        // left
        this->_durationLeft = true;
        this->_keyboardNameCache.push("LEFT");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
        break;

      case 27:
        // right
        this->_durationRight = true;
        this->_keyboardNameCache.push("RIGHT");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
        break;

      default:
        break;
    }
  }

  void HomeLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->_durationTop = false;

        if(this->_keyboardNameCache.top().compare("TOP") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;

      case 29:
        // bottom
        this->_durationBottom = false;

        if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;

      case 26:
        // left
        this->_durationLeft = false;

        if(this->_keyboardNameCache.top().compare("LEFT") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;

      case 27:
        // right
        this->_durationRight = false;

        if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
        }

        break;

      default:
        break;
    }
  }

  bool HomeLayer::onContactBegin(const cocos2d::PhysicsContact& contact)
  {
    this->_calculateContactPixel(contact);

    // std::cout<<"Begin->_contactedTop: "<<this->_contactedTop<<std::endl;
    // std::cout<<"Begin->_contactedBottom: "<<this->_contactedBottom<<std::endl;
    // std::cout<<"Begin->_contactedLeft: "<<this->_contactedLeft<<std::endl;
    // std::cout<<"Begin->_contactedRight: "<<this->_contactedRight<<std::endl;

    // std::cout<<"Begin->_contactedTopLeft: "<<this->_contactedTopLeft<<std::endl;
    // std::cout<<"Begin->_contactedTopRight: "<<this->_contactedTopRight<<std::endl;
    // std::cout<<"Begin->_contactedBottomLeft: "<<this->_contactedBottomLeft<<std::endl;
    // std::cout<<"Begin->_contactedBottomRight: "<<this->_contactedBottomRight<<std::endl;

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  

    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  

    }

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {
      if(this->_contactedTop == true)
      {
        obstacle->obstacleTop();
      }

      if(this->_contactedBottom == true)
      {
        obstacle->obstacleBottom();
      }

      if(this->_contactedLeft == true)
      {
        obstacle->obstacleLeft();
      }

      if(this->_contactedRight == true)
      {
        obstacle->obstacleRight();
      }

      if(this->_contactedTopLeft == true && this->_contactedTop == false && this->_contactedLeft == false)
      {
        obstacle->obstacleLeft();
        obstacle->obstacleTop();
      }

      if(this->_contactedTopRight == true && this->_contactedTop == false && this->_contactedRight == false)
      {
        obstacle->obstacleTop();
        obstacle->obstacleRight();
      }

      if(this->_contactedBottomLeft == true && this->_contactedBottom == false && this->_contactedLeft == false)
      {
        obstacle->obstacleBottom();
        obstacle->obstacleLeft();
      }

      if(this->_contactedBottomRight == true && this->_contactedBottom == false && this->_contactedRight == false)
      {
        obstacle->obstacleBottom();
        obstacle->obstacleRight();
      }
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  

    }

    return true;
  }

  bool HomeLayer::onContactSeparate(const cocos2d::PhysicsContact& contact)
  {
    this->_calculateContactPixel(contact);

    // std::cout<<"Separate->_contactedTop: "<<this->_contactedTop<<std::endl;
    // std::cout<<"Separate->_contactedBottom: "<<this->_contactedBottom<<std::endl;
    // std::cout<<"Separate->_contactedLeft: "<<this->_contactedLeft<<std::endl;
    // std::cout<<"Separate->_contactedRight: "<<this->_contactedRight<<std::endl;

    // std::cout<<"Separate->_contactedTopLeft: "<<this->_contactedTopLeft<<std::endl;
    // std::cout<<"Separate->_contactedTopRight: "<<this->_contactedTopRight<<std::endl;
    // std::cout<<"Separate->_contactedBottomLeft: "<<this->_contactedBottomLeft<<std::endl;
    // std::cout<<"Separate->_contactedBottomRight: "<<this->_contactedBottomRight<<std::endl;

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  

    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  

    }

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {
      if(this->_keyboardNameCache.top().compare("TOP") == 0)
      {
        if(this->_contactedBottom == true)
        {
          obstacle->unObstacleBottom();
        }
      }

      if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
      {
        if(this->_contactedTop == true)
        {
          obstacle->unObstacleTop();
        }
      }

      if(this->_keyboardNameCache.top().compare("LEFT") == 0)
      {
        if(this->_contactedRight == true)
        {
          obstacle->unObstacleRight();
        }
      }

      if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
      {
        if(this->_contactedLeft == true)
        {
          obstacle->unObstacleLeft();
        }
      }

      if(this->_contactedTop == false)
      {
        obstacle->unObstacleTop();
      }

      if(this->_contactedBottom == false)
      {
        obstacle->unObstacleBottom();
      }

      if(this->_contactedLeft == false)
      {
        obstacle->unObstacleLeft();
      }

      if(this->_contactedRight == false)
      {
        obstacle->unObstacleRight();
      }

      if(this->_contactedTopLeft == true && this->_contactedTop == false && this->_contactedLeft == false)
      {
        obstacle->unObstacleLeft();
        obstacle->unObstacleTop();
      }

      if(this->_contactedTopRight == true && this->_contactedTop == false && this->_contactedRight == false)
      {
        obstacle->unObstacleTop();
        obstacle->unObstacleRight();
      }

      if(this->_contactedBottomLeft == true && this->_contactedBottom == false && this->_contactedLeft == false)
      {
        obstacle->unObstacleBottom();
        obstacle->unObstacleLeft();
      }

      if(this->_contactedBottomRight == true && this->_contactedBottom == false && this->_contactedRight == false)
      {
        obstacle->unObstacleBottom();
        obstacle->unObstacleRight();
      }
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  

    }

    return true;
  }

  bool HomeLayer::_calculateContactPixel(const cocos2d::PhysicsContact& contact)
  {
    this->_contactedTop = false;
    this->_contactedBottom = false;
    this->_contactedLeft = false;
    this->_contactedRight = false;
    this->_contactedTopLeft = false;
    this->_contactedTopRight = false;
    this->_contactedBottomLeft = false;
    this->_contactedBottomRight = false;

    int counter = 0;
    int tmp = 0;

    // bottom
    for(tmp = 0; tmp < 30; tmp++)
    {
      if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX + tmp, this->_heroPositionY - 1)) == true)
      {
        counter++;
      }
    }

    if(counter >= 1)
    {
      this->_contactedBottom = true;
    }

    counter = 0;

    // left
    for(tmp = 0; tmp < 20; tmp++)
    {
      if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX - 1, this->_heroPositionY + tmp)) == true)
      {
        counter++;
      }
    }

    if(counter >= 1)
    {
      this->_contactedLeft = true;
    }

    counter = 0;

    // top
    for(tmp = 0; tmp < 30; tmp++)
    {
      if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX + tmp, this->_heroPositionY + 21)) == true)
      {
        counter++;
      }
    }

    if(counter >= 1)
    {
      this->_contactedTop = true;
    }

    counter = 0;

    // right
    for(tmp = 0; tmp < 20; tmp++)
    {
      if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX + 31, this->_heroPositionY + tmp)) == true)
      {
        counter++;
      }
    }

    if(counter >= 1)
    {
      this->_contactedRight = true;
    }

    // top left
    if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX - 1, this->_heroPositionY + 21)) == true)
    {
      _contactedTopLeft = true;
    }

    // top right
    if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX + 31, this->_heroPositionY + 21)) == true)
    {
      _contactedTopRight = true;
    }

    // bottom left
    if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX - 1, this->_heroPositionY - 1)) == true)
    {
      _contactedBottomLeft = true;
    }

    // bottom right
    if(contact.getShapeA()->containsPoint(cocos2d::Vec2(this->_heroPositionX + 31, this->_heroPositionY - 1)) == true)
    {
      _contactedBottomRight = true;
    }

    return true;
  }

  void HomeLayer::_nextStringCallback(cocos2d::Ref* pSender)
  {
    this->_firstLine->setString("Tomorrow is another day!");
    this->_firstLine->updateContent();

    this->_secondLine->setString("See you then.");
    this->_secondLine->updateContent();

    this->_thirdLine->setString("");
    this->_thirdLine->updateContent();
  }

}