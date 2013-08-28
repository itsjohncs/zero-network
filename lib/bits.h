inline bool bit8(uint8_t byte, uint bit) {
	if (bit >= 8) {
		// Critical because we don't have a way to signal to the rest of the
		// program that something went wrong.
		LOG_CRITICAL("bit[%u] out of bounds", bit);
		return false;
	}

	return ((byte >> bit) & 0x01) == 0x01;
}
