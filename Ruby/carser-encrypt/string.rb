class String
    def alpha?
        self.match(/[^A-Za-z0-9]/)
    end

    def upcase?
        not self.alpha? and self.upcase == self
    end

    def downcase?
        not self.alpha? and self.downcase == self
    end

    def byte
        self.bytes[0]
    end
end
