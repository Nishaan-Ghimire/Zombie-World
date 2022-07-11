/* 


for (size_t i = 0; i <allEnemies.enemyGroup.size(); i++)
{
    
   
           // Enemy Bullet timer
    if (BulletPack.enemyshootTimer < 10)
        BulletPack.enemyshootTimer++;
             
          //Enemy Bullet initialization, movement and Direction control 
    if (BulletPack.enemyshootTimer > 10)
    {
 
    cout<<"I am inside, X : "<<allEnemies.enemyGroup[i].enemySpeed.x<<endl;
   cout<<"I am inside, X : "<<allEnemies.enemyGroup[i].enemySpeed.y<<endl;
    // For every Rectangleshape bullet object which is to added to its vector structure is given origin as center of player
        bulletObj.bullet.setPosition(BulletPack.enemyBulletOrigin);
        // Setting texture for every Rectangleshape bullet object
        bulletObj.bullet.setTexture(&bulletObj.bulletTexture);
        // For changing bullet moving and texture direction by passing player direction enum as argument

        bulletObj.changeDirection(player.playerDirection, bulletObj.bullet, bulletObj.speed);

        // Loading ready Rectangleshape bullet object to ammunations vector
        BulletPack.enemyammunations.push_back(bulletObj);

        // resetting shoottimer to zero
        BulletPack.enemyshootTimer = 0;
    }
    
    
   
}












    // For Enemy bullet movement and removing bullet
    for (size_t j = 0; j < BulletPack.enemyammunations.size(); j++)
    {



        // Making the every bullet move by changing position of all bullet inside vector
        BulletPack.enemyammunations[j].bullet.move(BulletPack.enemyammunations[j].speed);

        // condition for erasing bullet if the cross the screen
        if (BulletPack.enemyammunations[j].getPosition().y < 0 || BulletPack.enemyammunations[j].getPosition().y >= window.getSize().y ||
            BulletPack.enemyammunations[j].getPosition().x < 0 || BulletPack.enemyammunations[j].getPosition().x >= window.getSize().x)
            BulletPack.enemyammunations.erase(BulletPack.enemyammunations.begin() + j);
    
}




 for (size_t j = 0; j < BulletPack.enemyammunations.size(); j++)
        {
            window.draw(BulletPack.enemyammunations[j].bullet);
        } 


           // Setting Enemy bullet Position

    for (size_t i = 0; i < allEnemies.enemyGroup.size(); i++)
    {
         for (size_t j = 0; j < BulletPack.enemyammunations.size(); j++)
    {
    BulletPack.enemyBulletOrigin = Vector2f(allEnemies.enemyGroup[i].enemy.getPosition().x + (allEnemies.enemyGroup[i].enemy.getSize().x / 2) + 10.0f, allEnemies.enemyGroup[i].enemy.getPosition().y + (allEnemies.enemyGroup[i].enemy.getSize().y / 2) + 10.0f);
    }
    }

 */