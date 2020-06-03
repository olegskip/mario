#include "audio_controller.h"

AudioController::AudioController()
{
}

void AudioController::startPlayingMusic()
{
	currentMusicIndex = 0;
	musicLoader.getObject(currentMusicIndex).play();
	musicLoader.getObject(currentMusicIndex).setVolume(volume);
}

void AudioController::playSound(SoundsID soundID)
{
	soundsLoader.getObject(soundID).setVolume(volume);
	soundsLoader.getObject(soundID).play();
	currentSoundID = soundID;
}

bool AudioController::toggleMute()
{
	if(volume == 100)
		mute();
	else
		unmute();
	
	return volume != 100;
}

void AudioController::mute()
{
	volume = 0;
	musicLoader.getObject(currentMusicIndex).setVolume(volume);
	soundsLoader.getObject(currentSoundID).stop();
}

void AudioController::unmute()
{
	volume = 100;
	musicLoader.getObject(currentMusicIndex).setVolume(volume);
	soundsLoader.getObject(currentSoundID).stop();
}

void AudioController::update()
{
	if(musicLoader.getObject(currentMusicIndex).getStatus() == sf::SoundStream::Status::Stopped) {
		musicLoader.getObject(currentMusicIndex).stop();
		if(++currentMusicIndex > musicLoader.getCount())
			currentMusicIndex = 0;
		musicLoader.getObject(currentMusicIndex).play();
		musicLoader.getObject(currentMusicIndex).setVolume(volume);
	}
}
