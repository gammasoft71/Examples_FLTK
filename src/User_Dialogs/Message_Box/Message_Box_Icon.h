#pragma once

enum class Message_Box_Icon {
  None = 0,
  Error = 0x00000010L,
  Question = 0x00000020L,
  Warning = 0x00000030L,
  Information = 0x00000040L,
  Hand = Error,
  Stop = Error,
  Exclamation = Warning,
  Asterisk = Information,
};
