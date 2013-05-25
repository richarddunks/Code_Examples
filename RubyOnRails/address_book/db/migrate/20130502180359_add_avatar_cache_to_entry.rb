class AddAvatarCacheToEntry < ActiveRecord::Migration
  def change
    add_column :entries, :avatar_cache, :string
  end
end
