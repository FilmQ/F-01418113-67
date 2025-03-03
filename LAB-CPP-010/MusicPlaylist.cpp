#include <iostream>
#include <string>

class MusicPlaylist
{
    private:
        std::string musicList[20];
        mutable int musicStored = 0;
        mutable int currentTrack = 0;

    public:
        void add(std::string songName) {
            musicList[musicStored] = songName;
            musicStored++;
        } 

        void setCurrentTrack(int songOrder) {
            currentTrack = songOrder - 1;
        }

        std::string play() {
            return musicList[currentTrack];
        }
};

int main() 
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(3);
    std::cout << mp.play() << std::endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}